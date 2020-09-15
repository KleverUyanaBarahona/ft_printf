#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd);
void    ft_putstr(const char *str);
void print_ints(int num , ...);
void printf_str(const char *format , ...);
//libreria
void    ft_putstr(const char *str)
{
    int a;

    a = 0;
    while (str[a])
    {
        write(1, &str[a], 1);
        a++;
    }
}

void    ft_putchar(char c)
{
  write(1, &c, 1);
}
void    ft_putnbr(int nb)
{
        long i;

        i = nb;
        if (i < 0)
        {
                ft_putchar('-');
                i = i * (-1);
        }
        if (i > 9)
        {
                ft_putnbr(i / 10);
                ft_putnbr(i % 10);
        }
        else
        {
                ft_putchar(i + '0');
        }
}


//*********

void print_ints(int num , ...)
{
    va_list args;
    int i;
    int aux;

    va_start(args, num);

    for ( i = 0; i < num; i++)
    {
        aux=0;
        int value = va_arg(args,int);
        printf("%d: %d\n",i+1, value);
        aux = value;
        ft_putnbr(aux);
        ft_putnbr(value);
    }
    va_end(args);

}
void printf_str(const char *format , ...)
{
    va_list args_printf;
    int i;
    void *done;
    va_start(args_printf,format);

    for (i = 0; i < 2; i++)
    {
        done = va_arg(args_printf,char*);
        printf("Cadena%d: %s\n",i, done);
    }

    va_end(args_printf);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    t_n *n;
    t_convspecs *cs;

    va_start(args, str);


    va_end(args);
    return 0;
}

static int _is_digit(char ch)
{
    if ((ch >= '0') && (ch <= '9'))
    {
        return 1;
    }
    
  return -1;
}

unsigned int _atoi(char** str)
{
  unsigned int i = 0U;
  while (_is_digit(**str)) {
    i = i * 10U + (unsigned int)(*((*str)++) - '0');
  }
  return i;
}

int main()
{
    char *m = "hola";
    int a = 2000;
    int cc;
    print_ints(4,123,2,4,5);
    printf_str("dddd", m , "1", 1 );

    printf("hola%s","\n");

    cc = printf("klever %li",15166515616);

    printf("\n%i\n",cc);
    char *p = "1236";
    printf("%i",_atoi(p));
    _atoi(p);

/*
    if (printf("Hola")==printf("Hola"))
    {
        printf("no son igluales");
    }
    else
    {
        printf("si no iguales");
    } 
  */  
    return 0;

}


