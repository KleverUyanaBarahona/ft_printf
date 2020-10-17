/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:43:17 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/17 19:43:07 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_un_special(t_var *var)
{
	print_spaces(var);
	var->str_count++;
}

void	print_un_r(t_var *var, unsigned int n, int n_len)
{
	if (var->zero == 1)
		print_zeros(var);
	else
		print_spaces(var);
	print_zeros_pad(var);
	ft_putnbr_uns_fd(n, 1);
	var->char_count += n_len;
}

void	print_un_l(t_var *var, unsigned int n, int n_len)
{
	print_zeros_pad(var);
	ft_putnbr_uns_fd(n, 1);
	var->char_count += n_len;
	print_spaces(var);
}

void	print_unsigned(t_var *var, int n)
{
	int				n_len;
	unsigned int	un;

	un = (unsigned int)n;
	n_len = ft_num_len(un);
	if (var->precision == 1 && var->precision_value == 0 && un == 0)
	{
		var->spaces = var->width;
		print_un_special(var);
		return ;
	}
	if (var->precision == 1)
	{
		var->zero = 0;
		if (var->precision_value >= n_len)
			var->zero_pad = var->precision_value - n_len;
		var->spaces = (var->width - (n_len + var->zero_pad));
	}
	else
		var->spaces = var->width - n_len;
	var->minus == 1 ? print_un_l(var, un, n_len) : print_un_r(var, un, n_len);
	var->str_count++;
}