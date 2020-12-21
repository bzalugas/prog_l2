#include <stdio.h>

int main()
{
    int a[ ]={12,23,34,45,56,67,78,89,90};
    int *p;
    p=a;

    printf("%p\n", &a[7]-p);
}
