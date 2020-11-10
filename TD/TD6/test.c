#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define NMAX 30

void chaineLire (char * s) {
  printf ("entrez une chaine d'au plus, %d, caractères :\n", NMAX-1);
  fgets(s, NMAX-1, stdin);
}
int main()
{
  char *ch;
  chaineLire(ch);
  printf("voila la belle chaine : %s", ch);
  return EXIT_SUCCESS;
}
