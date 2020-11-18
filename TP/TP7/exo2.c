#include <stdio.h>
#include <stdlib.h>

#define MAX 30

void    saisirTab(int t[], int nb)
{
    int i;

    for (i = 0; i < nb; i++)
        {
            printf("Entrer t[%d] : ", i);
            scanf("%d", &t[i]);
        }
}

void    afficheTab(int t[], int nb)
{
    int i;

    for(i = 0; i < nb; i++)
        printf("\t%d", t[i]);
    printf("\n\n");
}

void    inverseTab(int t[], int nb)
{
    int *p1, *p2, aide;
    p1 = t;
    p2 = &t[nb - 1];
    while (p1 < p2)
        {
            aide = *p1;
            *p1 = *p2;
            *p2 = aide;
            p1++;
            p2--;
        }
}

int     main(void)
{
    int *t, nb;

    do
        {
            printf("Rentrez le nombre d'éléments à saisir (nb <= %d): ", MAX);
            scanf("%d", &nb);
        } while (nb <= 0 || nb > MAX);
    if (!(t = (int *) malloc(sizeof(int) * nb)))
        {
            printf("erreur allocation mémoire.\n");
            exit (0);
        }
    saisirTab(t, nb);
    printf("*****\tAffichage du tableau initial\t******\n\nvecteur t:\t");
    afficheTab(t, nb);
    inverseTab(t, nb);
    printf("\n\n******\tAffichage du tableau après inversion\t******\n\nvecteur t inversé:");
    afficheTab(t, nb);
    free(t);
    return (0);
}
