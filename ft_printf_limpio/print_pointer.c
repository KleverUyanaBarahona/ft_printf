/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:12 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/19 21:11:02 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_ptr_prefix(t_var *var)
{
	ft_putstr_fd("0x", 1);
	var->char_count += 2;
}

void	print_ptr_special(t_var *var)
{
	var->spaces = var->width - 2;
	if (var->minus == 1)
	{
		add_ptr_prefix(var);
		print_spaces(var);
	}
	else
	{
		print_spaces(var);
		add_ptr_prefix(var);
	}
	var->str_count++;
}

void	print_ptr_l(t_var *var, char *str, int len)
{
	add_ptr_prefix(var);
	print_zeros_pad(var);
	ft_putstr_fd(str, 1);
	var->char_count += len;
	print_spaces(var);
}

void	print_ptr_r(t_var *var, char *str, int len)
{
	if (var->zero == 1)
	{
		add_ptr_prefix(var);
		print_zeros(var);
	}
	else
	{
		print_spaces(var);
		add_ptr_prefix(var);
	}
	print_zeros_pad(var);
	ft_putstr_fd(str, 1);
	var->char_count += len;
}

void	print_pointer(t_var *var, long unsigned int pointer)
{
	char	*str;
	int		len;

	if (var->precision == 1 && var->precision_value == 0 && pointer == 0)
	{
		print_ptr_special(var);
		return ;
	}
	int_to_hex_long_un(pointer, &str);
	len = ft_strlen(str);
	if (var->precision == 1)
	{
		var->zero = 0;
		if (var->precision_value >= len)
			var->zero_pad = var->precision_value - len;
		var->spaces = (var->width - (len + var->zero_pad) - 2);
	}
	else
		var->spaces = var->width - len - 2;
	var->minus == 1 ? print_ptr_l(var, str, len) : print_ptr_r(var, str, len);
	free(str);
	str = NULL;
	var->str_count++;
}
