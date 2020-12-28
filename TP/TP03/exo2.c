#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main(void)
{
  int nb, i;
  float *ptrMax=NULL, *ptrMin=NULL, *ptr;

  do
    {
      printf("Nb de valeurs réelles à saisir ? ");
      scanf("%d", &nb);
    } while (nb <= 0 || nb > MAX);
  if (!(ptr = (float *) calloc(nb,sizeof(int))))
    printf("erreur d'allocation mémoire.\n");
  for(i=0; i < nb; i++)
    {
      printf("valeur réelle n°%d ? ", i+1);
      scanf("%f", &ptr[i]);
    }
  ptrMax = ptr;
  ptrMin = ptr;
  for(i = 0; i < nb; i++)
    {
      if (*ptrMax < *(ptr+i))
        ptrMax = ptr+i;
      if (*ptrMin > *(ptr+i))
        ptrMin = ptr+i;
    }
  printf("****** Affichage de la suite de valeurs réelles saisies ******\n");
  for(i = 0; i < nb; i++)
    printf("Adresse valeur réelle n°%d : %p\tvaleur réelle n°%d : %.2f\n", i+1, ptr+i,i+1,*(ptr+i));
  printf("\n****** Affichage des minimum et maximum ******\n");
  printf("contenu de ptrMax : %p\tvaleur de la case pointée par ptrMax : %.2f\n", ptrMax, *ptrMax);
  printf("contenu de ptrMin : %p\tvaleur de la case pointée par ptrMin : %.2f\n", ptrMin, *ptrMin);
  free(ptr);
  return (0);
}
