#include <stdio.h>

int main(void)
{
	float a,b,s,p,c1,c2;

	printf("entrez deux entiers A et B : ");
	scanf("%f%f", &a,&b);
	s = a+b;
	p = a*b;
	c1 = a*a;
	c2 = b*b;
	printf("%.0f + %.0f = %.0f\n%.0f * %.0f = %.0f\ncarré de %.0f = %.0f\ncarré de %.0f = %.0f\n", a,b,s,a,b,p,a,c1,b,c2);
	return (0);
}
