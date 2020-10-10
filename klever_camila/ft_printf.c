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

	ft = ft_printf("");
	p = printf("%s","342");

	printf("\nft:%d",ft);
	printf("\np:%d\n",p);
	return 0;
}