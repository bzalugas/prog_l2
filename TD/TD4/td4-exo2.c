#include <stdio.h>

#define MAXL 10
#define MAXC 10

int main(void)
{
    int matrice[MAXL][MAXC], nbl, nbc, i, j;
    do
        {
            printf("Nb lignes : ");
            scanf("%d", &nbl);
        } while (nbl <= 0 || nbl > MAXL);
    do
        {
            printf("Nb colonnes : ");
            scanf("%d", &nbc);
        } while (nbc <= 0 || nbc > MAXL);
    for(i = 0; i < nbl; i++)
        {
            for(j = 0; j < nbc; j++)
                {
                    printf("matrice[%d][%d] : ", i,j);
                    scanf("%d", &matrice[i][j]);
                }
        }
    printf("\n*****Matrice entree ******\n");
    for(i = 0; i < nbl; i++)
        for(j = 0; j < nbc; j++)
            printf("matrice[%d][%d] : %d\n", i,j,matrice[i][j]);
    printf("\n");
    return (0);
}
