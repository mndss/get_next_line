/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:35:44 by elima-me          #+#    #+#             */
/*   Updated: 2021/06/18 18:42:46 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	char	*set;
	size_t	i;

	i = 0;
	pointer = malloc(nmemb * size);
	if (!pointer)
		return (NULL);
	set = (char *)pointer;
	while (i < size)
	{
		set[i] = '\0';
		i++;
	}
	return (pointer);
}

static char	*make_line(char **line, char **read_buffer)
{
	char	*temp;
	int		end_line;

	temp = NULL;
	end_line = ft_strchr(*read_buffer, '\n');
	if (end_line != -1)
	{
		read_buffer[0][end_line] = '\0';
		*line = ft_strdup(*read_buffer);
		end_line++;
		temp = ft_strdup(*read_buffer + end_line);
	}
	else
		*line = ft_strdup(*read_buffer);
	if (*read_buffer != NULL)
	{		
		free(*read_buffer);
		read_buffer = NULL;
	}	
	if (!line || !temp)
		return (NULL);
	return (temp);
}

int	read_and_join(int fd, char **read_buffer, char *line_buffer, int *bytes)
{
	char	*temp;
	char	*join_temp;
	size_t	size;

	while (*bytes && ft_strchr(*read_buffer, '\n') == -1)
	{
		*bytes = read(fd, line_buffer, BUFFER_SIZE);
		if (*bytes < 0 || BUFFER_SIZE < *bytes)
		{
			free(line_buffer);
			return (-1);
		}
		if (*bytes)
		{
			temp = NULL;
			if (*bytes < BUFFER_SIZE)
				temp = ft_strjoin(temp, line_buffer, *bytes);
			else
				temp = ft_strjoin(temp, line_buffer, BUFFER_SIZE + 1);
			size = ft_strlen(*read_buffer);
			join_temp = ft_strjoin(*read_buffer, temp, (BUFFER_SIZE + size));
			*read_buffer = join_temp;
			free(temp);
		}
	}
	free(line_buffer);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*read_buffer;
	char		*line_buffer;
	int			bytes;
	int			already_read;

	bytes = 1;
	if (fd < 0 || fd > RLIMIT_NOFILE || !(line) || BUFFER_SIZE <= 0)
		return (-1);
	line_buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!line_buffer)
		return (-1);
	if (!read_buffer)
		read_buffer = ft_strdup("");
	already_read = read_and_join(fd, &read_buffer, line_buffer, &bytes);
	if (already_read == -1 || !line)
		return (-1);
	read_buffer = make_line(line, &read_buffer);
	if (!bytes)
	{		
		free(read_buffer);
		return (0);
	}
	return (1);
}
