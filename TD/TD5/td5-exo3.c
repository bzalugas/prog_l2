#include <stdio.h>
int factorielle(int n)
{
    int i, result = 1;

    for(i = 0; i < n; i++)
        result *= (n - i);
    return (result);
}

int facto(int n)
{
    if (n > 0)
        return (n * facto(n - 1));
    else
        return (1);
}

int main(void)
    {
        int n, x, y;

        printf(" n ? ");
        scanf("%d", &n);
        x = factorielle(n);
        y = facto(n);
        printf("ite = %d, recur = %d\n", x, y);
        return (0);
    }
