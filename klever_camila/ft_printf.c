#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    va_list args;
}Mystruct;

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

int ft_vprintf(const char *format,Mystruct args)
{
    char chars;

    chars = 0;

while (*format)
{
    if (*format != '%')
    {
        write(1, format++, 1);
        chars +=1;
    }else if(*format++){
        if (*format == '%')
        {
            write(1,format,1);
            chars += 1;
            format++;
        }else{
            
        }        
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
    //char e = '%';

    ft = ft_printf("%%%%%%");
    p = printf("%%%%");

    printf("\nft:%d\n",ft);
    printf("p:%d\n",p);
    return 0;
}