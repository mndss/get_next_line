/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:35:44 by elima-me          #+#    #+#             */
/*   Updated: 2021/06/10 13:41:24 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	
}

 ____________________________________________

variavel statica = static variables are defined only once, and worked during all execution of our program. 

file descriptor  = fd is unique identifier for a file or other input/output ressource 
integer values =	0 standard input
					1 standard output
					2 standard error
--------------------
monta a logica do programa 
começar os codigos


// receive a pointer of pointer with the string; 
// needs separate this and read line to line;
// description = Calling my function gnl in a loop allow read the text avaliable 
// on a file descriptor one line at a time until the EOF.

// 1 = Learn about flag -D BUFFER_SIZE=xx with will the flag that my program must compile. 
// Basically is a flag that pass the size of line for my program read.

// 2 = Learn about how static variables works.


// #include <stdio.h>
// #include <unistd.h>

// int main(void)
// {
// 	char buff[15];
// 	size_t ret;

// 	ret = read(0, buff, 15);
// 	printf("\n%s\n", buff);
// 	return (0);
// }

// vou receber um ponteiro apontando para o endereço de um arquivo que eu vou ler 
// a função tem que retornar quantas vezes ela foi chamada para ler aquela linha e o conteudo da linha 
// 				estudar
// - file descriptor 
// - função open 
// - variavel estática
// -D BUFFER_SIZE=xx -> é a quantidade de buffer que eu vou ler a cada chamada da função. 
// EOF -> End of File. 
// 