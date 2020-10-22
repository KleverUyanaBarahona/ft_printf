/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafernan <cafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:30:51 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/22 18:07:04 by cafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_n_special(t_var *var)
{
	print_spaces(var);
	var->str_count++;
}

int		print_sign(int n)
{
	ft_putchar_fd('-', 1);
	n = n * -1;
	return (n);
}

void	print_n_r(t_var *var, int n, int n_len)
{
	if (var->zero == 1)
	{
		if (n < 0)
			n = print_sign(n);
		print_zeros(var);
	}
	else
	{
		if (var->aux == 1 && var->width <= var->precision_value &&
				var->precision == 1)
		{
			if (var->width != 0 && !(var->width == var->precision_value))
				var->spaces = 1;
		}
		print_spaces(var);
		if (n < 0)
			n = print_sign(n);
	}
	print_zeros_pad(var);
	ft_putnbr_fd(n, 1);
	var->char_count += n_len;
	var->str_count++;
}

void	print_n_l(t_var *var, int n, int n_len)
{
	if (var->aux == 1 && var->width <= var->precision_value &&
			var->precision == 1)
	{
		if (var->width != 0)
		{
			ft_putchar_fd(' ', 1);
			var->char_count++;
		}
	}
	if (var->aux == 1 && var->width >= var->precision_value &&
			var->precision == 1)
	{
		if (var->width != 0)
		{
			ft_putchar_fd(' ', 1);
			auxfuction(var);
		}
	}
	if (n < 0)
		n = print_sign(n);
	print_zeros_pad(var);
	ft_putnbr_fd(n, 1);
	print_spaces(var);
	var->char_count += n_len;
	var->str_count++;
}

void	print_decimal(t_var *var, int n)
{
	int	n_len;

	n_len = ft_num_len(n);
	if (var->precision == 1 && var->precision_value == 0 && n == 0)
	{
		var->spaces = var->width;
		print_n_special(var);
		return ;
	}
	if (var->precision == 1)
	{
		var->zero = 0;
		if (var->precision_value >= n_len)
		{
			if (n < 0)
				var->zero_pad = var->precision_value - (n_len - 1);
			else
				var->zero_pad = var->precision_value - n_len;
		}
		var->spaces = (var->width - (n_len + var->zero_pad));
	}
	else
		var->spaces = var->width - n_len;
	var->minus == 1 ? print_n_l(var, n, n_len) : print_n_r(var, n, n_len);
}
