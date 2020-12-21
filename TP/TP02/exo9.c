#include <stdio.h>

int main(void)
{
    int a,b,c;

    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);
    if (a == b && b == c)
        printf("triangle equilateral\n");
    else if (a == b || a == c || b == c)
        printf("triangle isocele\n");
    else if (a*a == (b*b + c*c))
        printf("triangle rectangle\n");
    else
        printf("triangle quelconque\n");
    return (0);
}
