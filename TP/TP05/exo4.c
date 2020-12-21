
#include <stdio.h>

int coeffBinome(int n, int k)
{
    if (n >= 2 && k > 0 && k < n)
        {
            return (coeffBinome(n-1,k-1) + coeffBinome(n-1,k));
        }
    else
        return (1);

}

int factorielle(int n)
{
    if (n > 1)
        return (factorielle(n - 1) * n);
    else
        return (1);
}

int coeffBinome_iterative(int n, int p)
{
    return (factorielle(n) / (factorielle(p) * (factorielle(n-p))));
}

int puissance(int x, int y)
{
    int i,result=1;

    for(i = y; i > 0; i--)
        result *= x;
    return (result);
}

int binome_newton(int x, int y, int n)
{
    int p;
    int result=0;

    for(p = 0; p <= n; p++)
        result += coeffBinome(n,p) * puissance(x,n-p) * puissance(y,p);
    return (result);
}

int main(void)
{
    int x,y,n;

    printf("x ? ");
    scanf("%d", &x);
    printf("y ? ");
    scanf("%d", &y);
    printf("n ? ");
    scanf("%d", &n);
    printf("(%d + %d)^%d = %d\n", x,y,n,binome_newton(x,y,n));
    return (0);
}
