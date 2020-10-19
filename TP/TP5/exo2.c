#include <stdio.h>

void    swap(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
    printf("before end of swap : x = %d, y = %d\n", *x, *y);
}

int     main(void)
{
    int param1, param2;

    printf("Parametres ? ");
    scanf("%d%d", &param1, &param2);
    printf("Before swap : x = %d; y = %d\n", param1, param2);
    swap(&param1, &param2);
    printf("After swap : x = %d; y = %d\n", param1, param2);
    return (0);
}
