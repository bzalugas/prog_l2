#include <stdio.h>

#define MAXL 10
#define MAXC 10

int main(void)
{
  int matrice[MAXL][MAXC], nbl, nbc, i, j;
  do
    {
      printf("Nb lignes dans la matrice (<=%d) : ", MAXL);
      scanf("%d", &nbl);
    } while (nbl <= 0 || nbl > MAXL);
  do
    {
      printf("Nb colonnes dans la matrice (<=%d) : ", MAXC);
      scanf("%d", &nbc);
    } while (nbc<= 0 || nbc > MAXC);

  for(i = 0; i < nbl; i++)
    {
      for(j = 0; j < nbc; j++)
        {
          printf("Valeur de matrice[%d][%d] : ", i,j);
          scanf("%d", &matrice[i][j]);
        }
    }
  printf("\n******\tAffichage de la matrice\t******\n");
  for(i = 0; i < nbl; i++)
    {
      for(j = 0; j < nbc; j++)
        printf("\t%d", matrice[i][j]);
      printf("\n");
    }
  printf("\n******\tAffichage de la matrice transposée\t******\n");
  //pour afficher la matrice transposée, on inverse simplement les lignes et les colonnes
  for(j = 0; j < nbc; j++)
    {
      for(i = 0; i < nbl; i++)
        printf("\t%d", matrice[i][j]);
      printf("\n");
    }
}
