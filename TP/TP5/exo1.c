#include <stdio.h>

int mult_2(int nb)
{
    if ((nb%2) == 0)
        return (1);
    else
        return (0);
}

int mult_3(int nb)
{
    if ((nb%3) == 0)
        return (1);
    else
        return (0);
}

int main(void)
{
    int nb;

    printf("Nb entier ? ");
    scanf("%d", &nb);
    printf("%d est ", nb);
    if (mult_2(nb) == 1)
        printf("pair");
    else if (mult_3(nb) == 1)
        printf("un multiple de 3");
    if ((nb % 6) == 0)
        printf(" et un multiple de 6");
    printf("\n");
    return (0);
}
