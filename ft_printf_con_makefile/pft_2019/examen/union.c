/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:51:21 by ccardozo          #+#    #+#             */
/*   Updated: 2020/01/28 18:29:09 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int contador, char **argumentos)
{
	int unsigned_ascii[255];
	int fila = 0, columna;

	if (contador == 3)
	{
		while ( fila < 255)
			unsigned_ascii[fila++] = 0;
		fila = 1;
		while (fila < 3)
		{
			columna = 0;
			while (argumentos[fila][columna])
			{
				if (!unsigned_ascii[(unsigned char)argumentos[fila][columna]])
				{
					unsigned_ascii[(unsigned char)argumentos[fila][columna]] = 1;
					write(1, &argumentos[fila][columna], 1);
				}
				columna++;
			}
			fila++;
		}  
	}
	write(1, "\n", 1);
	return (0);
}