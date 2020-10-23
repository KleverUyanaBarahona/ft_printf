/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 02:20:24 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/19 21:07:32 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	get_flags(const char *format, t_var *var)
{
	var->str_count++;
	while (ft_isalpha(format[var->str_count]) != 1 &&
			format[var->str_count] != '%')
	{
		if (format[var->str_count] == '-')
			var->minus = 1;
		else if (format[var->str_count] == '0')
			var->zero = 1;
		else if (ft_isdigit(format[var->str_count]) == 1)
			get_width(format, var);
		else if (format[var->str_count] == '*')
			get_width(format, var);
		else if (format[var->str_count] == '.')
		{
			var->precision = 1;
			get_precision(format, var);
		}
		var->str_count++;
	}
}
