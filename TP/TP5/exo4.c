#include <stdio.h>
#include <stdlib.h>

int coeffBinome(int x, int y, int n)
{
    if (n >= 2)
        {

        }
    else
        return (1);

}

int main(int ac, char **av)
{
    int x,y,n;

    if (ac == 3)
        {
            x = atoi(av[1]);
            y = atoi(av[2]);
            n = atoi(av[3]);
            printf("(%d + %d)^%d = %d\n", x,y,n,coeffBinome(x,y,n));
            return (0);
        }
    printf("Entrez 3 arguments.\n");
    return (1);
}
