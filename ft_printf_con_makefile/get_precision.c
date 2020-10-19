/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 03:13:05 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/19 21:05:27 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_precision_value(const char *format, t_var *var)
{
	int		i;
	int		j;
	char	*str;

	j = var->str_count;
	i = 0;
	while (ft_isdigit((int)format[var->str_count]) == 1)
	{
		i++;
		var->str_count++;
	}
	str = ft_substr(&format[j], 0, i);
	var->precision_value = ft_atoi(str);
	free(str);
	str = NULL;
}

void	get_precision(const char *format, t_var *var)
{
	var->str_count++;
	if (format[var->str_count] == '-')
	{
		var->precision = 0;
		while (ft_isalpha(format[var->str_count]) != 1)
			var->str_count++;
	}
	else if (ft_isalpha(format[var->str_count]) == 1)
		var->precision_value = 0;
	else if (ft_isdigit(format[var->str_count]) == 1)
		get_precision_value(format, var);
	else if (format[var->str_count] == '*')
	{
		var->precision_value = va_arg(var->args, int);
		var->str_count++;
		if (var->precision_value < 0)
			var->precision = 0;
	}
	var->str_count--;
}
