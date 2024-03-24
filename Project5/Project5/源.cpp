#include<stdio.h>
#include"БъЭЗ.h"
int main()
{
	struct List l = { "hongshaorou",10 };
	printf_s("%s\t%d",l.name,l.price);
	return 0;
}