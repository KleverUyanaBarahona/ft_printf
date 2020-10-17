#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int  main (){
	int ft;
	int p;
	char e = '%';

//p = printf("%-5c",'c');
	ft = ft_printf("%010u",100);
	p = printf("%10.6u",100);

	printf("\nft:%d",ft);
	printf("\np:%d\n",p);
	return 0;
}