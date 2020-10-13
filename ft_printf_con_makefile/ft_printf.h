/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:44:59 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/13 20:48:11 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

typedef struct	s_printf
{
	int		char_count;
	int		str_count;
	char	data_type;
	int		minus;
	int		zero;
	int		point;
	int		width;
	int		precision;
	int		precision_value;
	int		spaces;
	int		zero_pad;
	va_list	args;
}				t_var;

int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_num_len(long int num);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			init_values_t_var(t_var *var);
void			reset_values_t_var(t_var *var);
int				spect_format(const char *format);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_putchar_fd(char c, int fd);
int				ft_inspector_format(const char *format, t_var *vars);
char			get_data_type(const char *format);
void			print_caracter(t_var *var);
void			print_percentage(t_var *var);
void			print_spaces(t_var *vars);
void			print_zeros(t_var *vars);
void			print_zeros_pad(t_var *var);
void			get_flags(const char *format, t_var *var);
void			reverse_str(char **str);
void			get_width_value(const char *format, t_var *var);
void			get_width(const char *format, t_var *var);
void			get_precision_value(const char *format, t_var *var);
void			get_precision(const char *format, t_var *var);
void			ft_putstr_fd(char *s, int fd);
void			print_string(t_var *var, char *str);
void			print_str_r(t_var *var, char *str, int str_len);
void			print_str_l(t_var *var, char *str, int str_len);

#endif
