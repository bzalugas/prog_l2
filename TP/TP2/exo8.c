#include <stdio.h>

int main(void)
{
    int nb, tmp, somme=0, produit=1, moyenne, i;

    printf("Nb d'entiers désirés ? ");
    scanf("%d", &nb);
    for(i = 0; i < nb; i++)
        {
            printf("Nombre n°%d : ", i+1);
            scanf("%d", &tmp);
            somme += tmp;
            produit *= tmp;
        }
    moyenne = somme / nb;
    printf("somme = %d, produit = %d, moyenne = %d\n", somme, produit, moyenne);
    return (0);
}
