#include <stdio.h>
#include <stdlib.h>

#define MAX 30

void    saisie(int notes[], int nb)
{
    int i;

    for(i = 0; i < nb; i++)
        {
            printf("note n°%d : ", i+1);
            scanf("%d", &notes[i]);
        }
    printf("\n");
}

void    calcul(int notes[], int nb, int *moy, int *big, int *small)
{
    int i;
    //initialisation des valeurs
    *moy = notes[0];
    *big = notes[0];
    *small = notes[0];
    //lecture du tableau des notes
    for(i=1; i < nb; i++) //on commence à 1 car on q déjà utilisé les valeurs de notes[0]
        {
            if (*big < notes[i])
                *big = notes[i];
            if (*small > notes[i])
                *small = notes[i];
            *moy += notes[i];
        }
    *moy /= nb;
}

void    afficher(int notes[], int nb)
{
    int i;

    printf("******Affichage des notes enregistrées******\n");
    for(i = 0; i < nb; i++)
        printf("\tnote n°%d : %d\n", i+1, notes[i]);
    printf("********************************************\n");
}

int     main(void)
{
    int *notes, nb, moy=0, big=0, small=0;;
    //definition nb de notes
    do
        {
            printf("Nb de notes à saisir (max %d) : ", MAX);
            scanf("%d", &nb);
        } while (nb <= 0 || nb > MAX);
    //allocation dynamique du tableau qui va contenir les notes
    if (!(notes = (int *) malloc(sizeof(int) * nb)))
        {
            printf("erreur allocation mémoire.\n");
            exit (0);
        }
    saisie(notes,nb);
    calcul(notes,nb,&moy,&big,&small);
    afficher(notes, nb);
    printf("\nNote la + haute : %d\nNote la + basse : %d\nMoyenne : %d\n", big,small,moy);
    free(notes);
    return EXIT_SUCCESS;
}
