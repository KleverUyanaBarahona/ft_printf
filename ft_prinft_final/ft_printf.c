/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:17:37 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/14 18:09:13 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_var vars;

	init_values_t_var(&vars);
	va_start(vars.args, format);
	if (spect_format(format) == 0)
		return (0);
	while (format[vars.str_count] != '\0')
	{
		if (format[vars.str_count] == '%')
		{
			if (!(ft_inspector_format(format, &vars)))
				return (0);
			reset_values_t_var(&vars);
		}
		else
		{
			ft_putchar_fd(format[vars.str_count], 1);
			vars.char_count++;
			vars.str_count++;
		}
	}
	va_end(vars.args);
	return (vars.char_count);
}
