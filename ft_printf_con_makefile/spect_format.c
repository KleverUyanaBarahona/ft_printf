/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spect_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:27:47 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/10 20:30:50 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spect_format(const char *format)
{
	if (format == NULL)
		return (0);
	else if ((ft_strcmp(format, "\0") == 0) || (ft_strcmp(format, "%") == 0))
		return (0);
	return (1);
}
