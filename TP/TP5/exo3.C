#include <stdio.h>
#include <stdlib.h>

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

int main(int ac, char **av)
{
    int x,y,z,min, max;
    (void)ac;

    x = atoi(av[1]);
    y = atoi(av[2]);
    z = atoi(av[3]);
    min_max(x,y,z,&min,&max);
    printf("min = %d, max = %d\n", min, max);
    return (0);
}
