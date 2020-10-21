#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int  main (){
	int ft;
	int p;
	char e = '%';

//p = printf("%-5c",'c');
	ft = ft_printf("%*d", 0, 42);
	p = printf("%*d", 0, 42);

	printf("ft:%d",ft);
	printf("p:%d",p);
	return 0;
}