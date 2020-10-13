/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspector_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:09:27 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/13 02:18:04 by klever           ###   ########.fr       */
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
    return(1);
}