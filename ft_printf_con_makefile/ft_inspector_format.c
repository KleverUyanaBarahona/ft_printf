/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspector_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:09:27 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/13 20:48:28 by kbarahon         ###   ########.fr       */
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
    return(1);
}