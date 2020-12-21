#include <stdio.h>

#define MAX 30

int main(void)
{
  int t[MAX], tmp, i, j, nb;
  printf("Rentrez le nombre d'éléments à saisir (nb <= %d): ", MAX);
  scanf("%d", &nb);
  for (i = 0; i < nb; i++)
    {
      printf("Entrer t[%d] : ", i);
      scanf("%d", &t[i]);
    }
  printf("\n\n");
  printf("*****\tAffichage du tableau initial\t******\n\nvecteur t:\t");
  for(i = 0; i < nb; i++)
    printf("\t%d", t[i]);
  for(i = 0, j = nb-1; i < j; i++, j--)
    {
      tmp = t[i];
      t[i] = t[j];
      t[j] = tmp;
    }
  printf("\n\n******\tAffichage du tableau après inversion\t******\n\nvecteur t inversé:");
  for(i = 0; i < nb; i++)
    printf("\t%d", t[i]);
  printf("\n");
}
