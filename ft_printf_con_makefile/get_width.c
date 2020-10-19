/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 02:33:45 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/19 20:54:49 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width_value(const char *format, t_var *var)
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
	var->width = ft_atoi(str);
	var->str_count--;
	free(str);
	str = NULL;
}

void	get_width(const char *format, t_var *var)
{
	if (ft_isdigit(format[var->str_count]) == 1)
		get_width_value(format, var);
	else if (format[var->str_count] == '*')
	{
		var->width = va_arg(var->args, int);
		if (var->width < 0)
		{
			var->minus = 1;
			var->width *= -1;
		}
	}
}
