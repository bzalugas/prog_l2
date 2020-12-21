#include <stdio.h>

#define MIN 0
#define MAX 50

int main(void)
{
  int t[MAX], t1[MAX], i, j, nb, effectif;

  //boucle tant que nb n'est pas correct
  do
    {
      printf("Rentrez le nombre d'éléments à saisir (nb <= %d): ", MAX);
      scanf("%d", &nb);
    } while (nb > MAX || nb <= MIN);
  printf("****Les chiffres doivent être rentrés par ordre croissant ****\n");
  //on entre les nombres
  for(i = 0; i < nb; i++)
    {
      //on vérifie a chaque nb entré qu'il est >= au nb d'avant
      do
        {
          printf("Entrez le chiffre n° %d : ", i+1);
          scanf("%d", &t[i]);
        } while (i > 0 && (t[i-1] > t[i]));
    }
  printf("\n");
  printf("******Affichage du tableau initial *******\nvecteur t:");
  for(i = 0; i < nb; i++)
    {
      printf("\t%d", t[i]);
    }
  i = 0;
  printf("\n");
  printf("\n");
  printf("******Affichage du tableau après et des effectifs ******\nvecteur t1:");
  for(j = 0; i < nb; j++)
    {
      t1[j] = t[i]; //on entre automatiquement la 1ère valeur
      do
        i++; //on incrémente forcément le i car on vient d'utiliser cette case du tableau
      while (i < MAX && (t[i-1] == t[i]));
      printf("\t%d", t1[j]);
    }
  printf("\neffectif  :");
  i = 0;
  effectif = 0;
  for(j = 0; i < nb; j++)
    {
      do
        {
          effectif++;
          i++;
        }
      while (i < MAX && (t[i] == t1[j]));
      printf("\t%d", effectif);
      effectif = 0; //on remet effectif à 0 pour la prochaine valeur redondante
    }
  printf("\n");
  return (0);
}
