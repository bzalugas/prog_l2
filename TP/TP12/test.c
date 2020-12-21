#include <stdio.h>

int test(char c)
{
    static int nb;
    ++nb;
    if (c < 'f')
        test(++c);
    return (nb);
}

int main()
{
    int n;

    n = test('a');
    printf("n = %d\n", n);
    return (0);
}
