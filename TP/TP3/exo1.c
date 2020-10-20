#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int x = 15;
  printf("Après définition et initialisation de x\n");
  printf("adresse de x: %p, valeur de x: %d\n", &x,x);
  int *pInt = &x;
  printf("Après définition et initialisation de pInt\n");
  printf("adresse de pInt: %p, contenu de pInt: %p, valeur de la case pointée par pInt: %d\n", &pInt, pInt, *pInt);
  int *ptrInt = malloc(sizeof(int));
  *ptrInt = 100;
  printf("Après allocation et initialisation de ptrInt\n");
  printf("adresse de ptrInt: %p, contenu de ptrInt: %p, valeur de la case pointée par ptrInt: %d\n", &ptrInt, ptrInt, *ptrInt);
  free(ptrInt);
  printf("****** Après instruction de modification de la valeur pointée par pInt ******\n");
  *pInt = 200;
  printf("adresse de pInt: %p, contenu de pInt: %p, valeur de la case pointée par pInt: %d\n", &pInt, pInt, *pInt);
  printf("adresse de x: %p, valeur de x: %d\n", &x,x);
}
