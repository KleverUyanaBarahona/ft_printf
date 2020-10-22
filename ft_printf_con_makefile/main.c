#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int  main (){
	int ft;
	int p;
	char e = '%';

//p = printf("%-5c",'c');
	ft = ft_printf("%.0x", 0);
	p = printf("%.0X", 0);

	printf("ft:%d",ft);
	printf("p:%d",p);
	return 0;
}