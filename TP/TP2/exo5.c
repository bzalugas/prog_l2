#include <stdio.h>

int main(void)
{
    int x,p,n,nb,i;

    printf("x ? ");
    scanf("%d", &x);
    printf("p ? ");
    scanf("%d", &p);
    printf("n ? ");
    scanf("%d", &n);
    //génération du masque (= 2^n - 1 << p - 1)
    nb = 1;
    for(i=0; i < n; i++)
        nb *= 2; //on trouve la puissance de 2 maximale pour le x choisit
    nb -= 1; // on soustrait 1 (formule)
    nb = nb << (p-1); // on décale à gauche p-1 bits dans nb
    nb = nb ^ x; // ou exclusif qui permet de mettre à 1 si les bits sont identiques et 0 sinon
    printf("nombre de depart = %d, nombre apres inversion des %d bits au rang %d = %d", x,n,p,nb);
    return (0);
}
