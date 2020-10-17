/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 20:03:18 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/17 20:04:05 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	itox_upper(unsigned int num, char **str)
{
	unsigned int	n;
	int				mod;
	char			*temp;
	int				i;

	n = num;
	i = 1;
	while ((n = n / 16) != 0)
		i++;
	temp = (char*)malloc(i + 1);
	temp[i] = '\0';
	i = 0;
	if (num == 0)
		temp[i] = 0 + 48;
	while (num != 0)
	{
		mod = num % 16;
		temp[i++] = mod < 10 ? mod + 48 : mod + 55;
		num = num / 16;
	}
	*str = temp;
	reverse_str(str);
}

void	itox_lower(unsigned int num, char **str)
{
	unsigned int	n;
	int				mod;
	char			*temp;
	int				i;

	n = num;
	i = 1;
	while ((n = n / 16) != 0)
		i++;
	temp = (char*)malloc(i + 1);
	temp[i] = '\0';
	i = 0;
	if (num == 0)
		temp[i] = 0 + 48;
	while (num != 0)
	{
		mod = num % 16;
		temp[i++] = mod < 10 ? mod + 48 : mod + 87;
		num = num / 16;
	}
	*str = temp;
	reverse_str(str);
}

void	int_to_hex(t_var *var, unsigned int num, char **str)
{
	if (var->data_type == 'x' || var->data_type == 'p')
		itox_lower(num, str);
	if (var->data_type == 'X')
		itox_upper(num, str);
}