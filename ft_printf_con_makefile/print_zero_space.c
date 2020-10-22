/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafernan <cafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:19:15 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/22 18:08:28 by cafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spaces(t_var *vars)
{
	while (vars->spaces > 0)
	{
		ft_putchar_fd(' ', 1);
		vars->char_count++;
		vars->spaces--;
	}
}

void	print_zeros(t_var *vars)
{
	while (vars->spaces > 0)
	{
		ft_putchar_fd('0', 1);
		vars->char_count++;
		vars->spaces--;
	}
}

void	print_zeros_pad(t_var *var)
{
	while (var->zero_pad > 0)
	{
		ft_putchar_fd('0', 1);
		var->char_count++;
		var->zero_pad--;
	}
}

void	auxfuction(t_var *var)
{
	var->char_count++;
	var->spaces--;
}
