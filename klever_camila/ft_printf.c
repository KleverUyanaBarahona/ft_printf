#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    va_list args;
}Mystruct;

char	ft_chardup(const char *s1)
{
	char	ne;
	int		i;
	
    i = 0;
	while (s1[1])
	{
		ne = s1[i];
		i++;
	}
	
	return ne;
}

void    ft_putchar(char c)
{
  write(1, &c, 1);
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

void ft_espec_format(char caracter ,int *chars, Mystruct vars)
{
    char char_aux;
    if(caracter=='c'){
        char_aux = va_arg(vars.args,int);
        ft_putchar(char_aux);
        *chars = *chars+1;
    }else if (caracter == '%'){
        ft_putchar('%');
        *chars = *chars+1;
    }
}

int ft_vprintf(const char *format, Mystruct var){
    int chars;

    chars = 0;
    char aux;
while (*format)
    {
        if (*format != '%')
        {
        write(1, format++, 1);
        chars +=1;
    }else{
        format++;
        aux = ft_chardup(format);
        ft_espec_format(aux,&chars,var);
    }

}

    return chars;
}


int ft_printf(const char *format,...)
{
    int prin_chars;
    Mystruct var;
    //va_list args;

    prin_chars = 0;
    va_start(var.args,format);
    
    if(format==NULL)
    return -1;
    else if ((ft_strcmp(format,"\0") == 0)||(ft_strcmp(format,"%") == 0))
    return 0;

    prin_chars = ft_vprintf(format, var);
    
    va_end(var.args);
    return prin_chars;
}

int  main (){
    int ft;
    int p;
    char e = '%';
    
    ft = ft_printf("kleve%c" ,37);
    p = printf("%c%c",37,37);

    printf("\nft:%d\n",ft);
    printf("p:%d\n",p);
    return 0;
}