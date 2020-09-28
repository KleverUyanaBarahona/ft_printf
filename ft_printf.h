/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:51:49 by kbarahon          #+#    #+#             */
/*   Updated: 2020/09/28 17:56:00 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

typedef struct	s_n
{
	long long int	*arg;
	long long int	nchr;
	struct s_n		*prev;
	struct s_n		*next;
}				t_n;

typedef struct	s_convspecs
{
	char			sign;
	char			adj;
	char			padd;
	char			alt;
	int				width;
	int				pre;
	char			len;
	char			spec;
}				t_convspecs;

#endif