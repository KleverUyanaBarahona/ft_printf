/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:12:05 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/19 21:03:48 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_data_type(const char *format)
{
	int i;

	i = 1;
	while (!ft_isalpha(format[i]) && format[i] != '%' && format[i] != '\0')
		i++;
	return (format[i]);
}
