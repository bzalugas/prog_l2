#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define NMAX 31

void chaineLire (char * s) {
  printf ("entrez une chaine d'au plus %d caractères :\n", NMAX-1);
  fgets(s, NMAX, stdin);
}
int main()
{
  char *ch=NULL;
  chaineLire(ch);
  printf("voila la belle chaine : %s", ch);
  return EXIT_SUCCESS;
}
