/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_caracter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:15:03 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/22 19:06:14 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_caracter(t_var *var)
{
	if (var->width > 1)
	{
		var->spaces = var->width - 1;
		if (var->minus == 1)
		{
			ft_putchar_fd(va_arg(var->args, int), 1);
			print_spaces(var);
		}
		else
		{
			print_spaces(var);
			ft_putchar_fd(va_arg(var->args, int), 1);
		}
	}
	else
		ft_putchar_fd(va_arg(var->args, int), 1);
	var->char_count++;
	var->str_count++;
}
