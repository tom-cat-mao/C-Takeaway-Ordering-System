#include<stdio.h>
#include"БъЭЗ.h"
void print();
int main()
{
	struct List l = { "hongshaorou",10 };
	printf_s("%s\t%d",l.name,l.price);
	print();
	return 0;
}