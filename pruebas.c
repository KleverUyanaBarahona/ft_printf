#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "./ft_printf.h"

int contador_variables(const char *str);

void	ft_putchar_fd(char c, int fd)
{
    fd = 1;
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void    ft_putcharstr(const char *str)
{
        write(1, &str[0], 1);

}
void contador_variables2(const char *str){

    char *conver;
    char *flags;
    flags = "#-+ .*0123456789hljz";
    conver = "cspdiouxXf%";
    static int aux;
    aux = 0;
    int i = 0;
  while (*str)
  {
      if(str==)

      str++;
    i++;
  }
}

void save_args(const char *str, ...)
{
    va_list args;

    va_start(args, str);

    int aux;
    aux = 0;   
    aux = contador_variables(str);
    contador_variables2(str);
    va_end(args);
}

int contador_variables(const char *str){

    static int aux;
    aux = 0;

  while (*str)
  {
      if(*str == '%')
      aux++;
      str++;
  }
  printf("%d",aux);
  return aux;
}

int main()
{
    save_args("%d%d",1,1);
    //printf("\\");
    return 0;

}