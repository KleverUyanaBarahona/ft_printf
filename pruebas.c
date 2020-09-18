#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "./ft_printf.h"


void save_args(const char *str, ...)
{
    va_list args;

    
    va_start(args, str);

    printf("%u\n",args->fp_offset);
    printf("%u\n",args->gp_offset);
    printf("%s\n",args->overflow_arg_area);
    printf("%s\n",args->reg_save_area);
    printf("%u\n",args->fp_offset);
    printf("%u\n",args->gp_offset);
    printf("%s\n",args->overflow_arg_area);
    printf("%s\n",args->reg_save_area);
    int e = 0;;
    while(args == NULL)
    {   
        e++;
    }
    printf("%d", e);

    
    va_end(args);

;
}

int main()
{
    save_args("klever","klever",1,"kleve");
    return 0;

}