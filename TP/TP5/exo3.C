#include <stdio.h>

void min_max(int x, int y, int z, int *min, int *max)
{
    *min = x;
    *max = x;
    if (*min > y)
        *min = y;
    if (*min > z)
        *min = z;
    if (*max < y)
        *max = y;
    if (*max < z)
        *max = z;
}

int main(void)
{
    int x,y,z,min, max;

    printf("valeur 1 : ");
    scanf("%d", &x);
    printf("valeur 2 : ");
    scanf("%d", &y);
    printf("valeur 3 : ");
    scanf("%d", &z);
    min_max(x,y,z,&min,&max);
    printf("min = %d, max = %d\n", min, max);
    return (0);
}
