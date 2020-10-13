#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int  main (){
	int ft;
	int p;
	char e = '%';

//p = printf("%-5c",'c');
	ft = ft_printf("%-20c%20c",'x','x');
	p = printf("%20c",'c');

	printf("\nft:%d",ft);
	printf("\np:%d\n",p);
	return 0;
}