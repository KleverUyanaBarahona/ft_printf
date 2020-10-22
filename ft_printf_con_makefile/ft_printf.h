/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:44:59 by kbarahon          #+#    #+#             */
/*   Updated: 2020/10/22 02:24:33 by klever           ###   ########.fr       */
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
	int		aux;
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
void			print_decimal(t_var *var, int n);
void			print_n_l(t_var *var, int n, int n_len);
void			print_n_r(t_var *var, int n, int n_len);
int				print_sign(int n);
void			print_n_special(t_var *var);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_uns_fd(unsigned int n, int fd);
void			print_un_special(t_var *var);
void			print_un_r(t_var *var, unsigned int n, int n_len);
void			print_un_l(t_var *var, unsigned int n, int n_len);
void			print_unsigned(t_var *var, int n);
void			itox_upper(unsigned int num, char **str);
void			itox_lower(unsigned int num, char **str);
void			int_to_hex(t_var *var, unsigned int num, char **str);
void			print_hex_special(t_var *var);
void			print_hex_r(t_var *var, char *str, int len);
void			print_hex_l(t_var *var, char *str, int len);
void			print_hexadecimal(t_var *var, unsigned int n);
void			add_ptr_prefix(t_var *var);
void			print_ptr_special(t_var *var);
void			print_ptr_l(t_var *var, char *str, int len);
void			print_ptr_r(t_var *var, char *str, int len);
void			print_pointer(t_var *var, long unsigned int pointer);
void			int_to_hex_long_un(long unsigned int num, char **str);

#endif
