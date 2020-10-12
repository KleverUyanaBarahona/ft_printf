#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int  main (){
	int ft;
	int p;
	char e = '%';

	ft = ft_printf("123");
	p = printf("%s","342");

	printf("\nft:%d",ft);
	printf("\np:%d\n",p);
	return 0;
}