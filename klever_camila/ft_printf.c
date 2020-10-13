#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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

void	init_values_t_var(t_var *var)
{
	var->char_count = 0;
	var->str_count = 0;
	var->data_type = ' ';
	var->minus = 0;
	var->zero = 0;
	var->point = 0;
	var->width = 0;
	var->precision = 0;
	var->precision_value = 0;
	var->spaces = 0;
	var->zero_pad = 0;
}

void	reset_values_t_var(t_var *var)
{
	var->data_type = ' ';
	var->minus = 0;
	var->zero = 0;
	var->point = 0;
	var->width = 0;
	var->precision = 0;
	var->precision_value = 0;
	var->spaces = 0;
	var->zero_pad = 0;
}

int		ft_atoi(const char *str)
{
	int			i;
	long int	sign;
	long int	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\r' || str[i] == '\n'
							|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
		if (sign * result > 2147483647)
			return (-1);
		else if (sign * result < -2147483648)
			return (0);
	}
	return (sign * result);
}

//************** str_function.c

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*sub;
	size_t	i;

	str = (char *)s;
	i = 0;
	if (str == NULL)
		return (NULL);
	if (!(sub = (char *)malloc(len + 1)))
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (str[i] != '\0' && i < len)
		{
			sub[i] = str[i + start];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}

//**************

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}

char	get_data_type(const char *format)
{
	int i;

	i = 0;
	while (!ft_isalpha(format[i]) && format[i] != '%' && format[i] != '\0')
		i++;
	return (format[i]);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	print_spaces(t_var *vars)
{
	while (vars->spaces > 0)
	{
		ft_putchar_fd(' ', 1);
		vars->char_count++;
		vars->spaces--;
	}
}

void	print_zeros(t_var *vars)
{
	while (vars->spaces > 0)
	{
		ft_putchar_fd('0', 1);
		vars->char_count++;
		vars->spaces--;
	}
}

void	print_caracter(t_var *var)
{
	if (var->width > 1)
	{
		var->spaces = var->width - 1;
		if (var->minus == 1)
		{
			ft_putchar_fd(va_arg(var->args, int), 1);
			print_spaces(var);
		}
		else
		{
			print_spaces(var);
			ft_putchar_fd(va_arg(var->args, int), 1);
		}
	}
	else
		ft_putchar_fd(va_arg(var->args, int), 1);
	var->char_count++;
	var->str_count++;
}

void	print_percentage(t_var *var)
{
	if (var->width > 1)
	{
		var->spaces = var->width - 1;
		if (var->minus == 1)
		{
			ft_putchar_fd('%', 1);
			print_spaces(var);
		}
		else
		{
			if (var->zero == 1)
				print_zeros(var);
			else
				print_spaces(var);
			ft_putchar_fd('%', 1);
		}
	}
	else
		ft_putchar_fd('%', 1);
	var->char_count++;
	var->str_count++;
}



void get_width_value(const char *format, t_var *vars)
{
	int i;
	int j;
	char *str;

	j = vars->str_count;
	i = 0;
	while (ft_isdigit((int)format[vars->char_count]) == 1)
	{
		i++;
		vars->str_count++;
	}
	str = ft_substr(&format[j], 0, i);
	vars->width = ft_atoi(str);
	vars->str_count--;
	free(str);
	str = NULL;	
}

void get_width(const char *format, t_var *vars)
{
	if (ft_isdigit(format[vars->str_count] == 1))
		get_width_value(format, vars);
	else if (format[vars->str_count] == '*')
	{
		vars->width = va_arg(vars->args, int);
		if (vars->width < 0)
		{
			vars->minus = 1;
			vars->width *= -1;
		}	
	}
}

void get_precision_value(const char *format, t_var *vars)
{
	int i;
	int j;
	char *str;

	j = vars->str_count;
	i = 0;
	while (ft_isdigit((int)format[vars->str_count]) == 1)
	{
		i++;
		vars->str_count++;
	}
	str = ft_substr(&format[j], 0, i);
	vars->width = ft_atoi(str);
	vars->str_count--;
	free(str);
	str = NULL;	
}

void get_precision(const char *format, t_var *vars)
{
	vars->str_count++;
	if (format[vars->str_count] == '-')
	{
		vars->precision = 0;
		while (ft_isalpha(format[vars->str_count]) != 1)
			vars->str_count++;
		
	}
	else if (ft_isalpha(format[vars->str_count]) == 1)
		vars->precision_value = 0;
	else if (ft_isdigit(format[vars->str_count]) == 1)
		get_precision_value(format, vars);
	else if (format[vars->str_count] == '*')
	{
		vars->precision_value = va_arg(vars->args, int);
		vars->str_count++;
		if (vars->precision_value < 0)
			vars->precision = 0;
	}
	vars->str_count--;
}

void get_flags(const char *format, t_var *vars){

	vars->str_count++;
	while (ft_isalpha(format[vars->str_count]) != 1 && format[vars->str_count] != '%')
	{
		if (format[vars->str_count] == '-')
			vars->minus = 1;
		else if (format[vars->str_count] == '0')
			vars->zero = 1;
		else if (ft_isdigit(format[vars->str_count]) == 1)
			get_width(format, vars);
		else if (format[vars->str_count] == '*')
			get_width(format, vars);
		else if (format[vars->str_count] == '.')
		{
			vars->precision = 1;
			get_precision(format, vars);
		}	
	}
}

int ft_strcmp(const char *s1,const char *s2)
{
	int i;
	i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int ft_inspector_format(const char *format, t_var *vars)
{
    if (!(vars->data_type = get_data_type(&format[vars->str_count])))
        return (0);
	get_flags(format, vars);    
    if (vars->data_type == 'c')
		print_caracter(vars);
	else if (vars->data_type == '%')
		print_percentage(vars);
//    else if (vars->data_type == '%')
//		print_percentage(vars);
    return(1);
}

/*
void *ft_vprintf(const char *format, t_var *vars){

while (format[vars->str_count]!='\0')
    {
        if (format[vars->str_count] != '%')
        {
        ft_putchar_fd(format[vars->str_count],1);
		vars->char_count+=1;
        }else if(format[vars->str_count++])
        {
            if (!(ft_inspector_format(format,&vars)))
                return (0);
            reset_values_t_var(&vars);
        }
    vars->str_count++;
    }
}
*/

int spect_format(const char *format){

	if(format == NULL)
    return (0);
    else if ((ft_strcmp(format,"\0") == 0)||(ft_strcmp(format,"%") == 0))
    return (0);
	return (1);
}


int ft_printf(const char *format, ...)
{
    t_var vars;

    init_values_t_var(&vars);
    va_start(vars.args,format);
	if (spect_format(format) == 0)
	return (0);
	while (format[vars.str_count] != '\0')
	{
		if (format[vars.str_count] != '%')
		{
			ft_putchar_fd(format[vars.str_count],1);
			vars.char_count++;
			vars.str_count++;
		}
		else if(format[vars.str_count++])
		{
			if (!(ft_inspector_format(format,&vars)))
			return (0);
			reset_values_t_var(&vars);
		}
	}
	va_end(vars.args);
    return (vars.char_count);
}

int  main (){
	int ft;
	int p;
	char e = '%';

	ft = ft_printf("%c",'c');
	p = printf("%5c",'c');

	printf("\nft:%d",ft);
	printf("\np:%d\n",p);
	return 0;
}