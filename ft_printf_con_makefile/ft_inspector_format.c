/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspector_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:09:27 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/18 23:41:01 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_inspector_format(const char *format, t_var *vars)
{
if (!(vars->data_type = get_data_type(&format[vars->str_count])))
        return (0);
    get_flags(format, vars);
    if (vars->data_type == 'c')
        print_caracter(vars);
    else if (vars->data_type == '%')
        print_percentage(vars);
	else if (vars->data_type == 's')
		print_string(vars, va_arg(vars->args, char *));
	else if (vars->data_type == 'd' || vars->data_type == 'i')
		print_decimal(vars, va_arg(vars->args, int));
	else if (vars->data_type == 'u')
		print_unsigned(vars, va_arg(vars->args, int));
    else if (vars->data_type == 'x' || vars->data_type == 'X')
		print_hexadecimal(vars, (unsigned int)va_arg(vars->args, int));
    else if (vars->data_type == 'p')
		print_pointer(vars, (long unsigned int)va_arg(vars->args, void *));
    return(1);
}
