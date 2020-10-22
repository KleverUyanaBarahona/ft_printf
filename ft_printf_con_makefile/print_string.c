/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:28:44 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/20 19:48:21 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str_l(t_var *var, char *str, int str_len)
{
	char	*aux;

	aux = ft_substr(str, 0, str_len);
	ft_putstr_fd(aux, 1);
	free(aux);
	aux = NULL;
	print_spaces(var);
}

void	print_str_r(t_var *var, char *str, int str_len)
{
	char	*aux;

	var->zero == 1 ? print_zeros(var) : print_spaces(var);
	aux = ft_substr(str, 0, str_len);
	ft_putstr_fd(aux, 1);
	free(aux);
	aux = NULL;
}

void	print_string(t_var *var, char *str)
{
	int		len;

	if (str == NULL)
		str = "(null)";
	if (var->precision == 1 && var->precision_value == 0)
		str = " ";
	len = ft_strlen(str);
	if (var->precision == 1 && var->precision_value < len)
		len = var->precision_value;
	var->spaces = var->width - len;
	if (var->spaces < 0)
		var->spaces = 0;
	if (var->minus == 1)
		print_str_l(var, str, len);
	else
		print_str_r(var, str, len);
	str = NULL;
	var->char_count += (len + var->spaces);
	var->str_count++;
}
