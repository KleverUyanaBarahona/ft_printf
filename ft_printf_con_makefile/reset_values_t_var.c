/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_values_t_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:23:38 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/10 20:28:18 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_values_t_var(t_var *var)
{
	var->data_type = ' ';
	var->minus = 0;
	var->zero = 0;
	var->point = 0;
	var->width = 0;
	var->precision = 0;
	var->precision_value = 0;
	var->spaces = 0;
	var->zero_pad = 0;
}
