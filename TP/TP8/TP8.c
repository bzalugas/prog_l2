#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM_MAX 30
#define EMPLOYE_MAX 5

typedef struct date {
    unsigned int    jour;
    unsigned int    mois;
    int             annee;
} date;

typedef struct employe {
    char    nom[NOM_MAX];
    date    date_embauche;
    date    date_poste;
} employe;
/*
char *read_str(void)
{
    char *str;
    char buffer[NOM_MAX];
    fgets(buffer, NOM_MAX, stdin);
    if (!(str = (char *) malloc(sizeof(char) * (strlen(buffer)+1))))
        {
            printf("erreur allocation mémoire");
            exit (0);
        }
    strcpy(str, buffer);
    return (str);
} */

void    saisie(employe *p)
{
    char rep;
    fflush(stdin);
    printf("Nom : ");
/*    char *nom = read_str();
    if (strlen(nom) < NOM_MAX)
        nom[strlen(nom) - 1] = '\0';
    strcpy(p->nom, nom);
    free(nom); */
    scanf("%s", p->nom);
    fflush(stdin);
    printf("Date embauche (jj mm aa) : ");
    scanf("%u %u %d", &p->date_embauche.jour,&p->date_embauche.mois,&p->date_embauche.annee);
    do
        {
            fflush(stdin);
            printf("Date poste = date embauche ? (O/N) : ");
            scanf("%c", &rep);
            switch(rep)
                {
                case 'O':case'o':
                    p->date_poste = p->date_embauche;
                    break;
                case 'N':case'n':
                    printf("Date poste (jj mm aa) : ");
                    fflush(stdin);
                    scanf("%u %u %d", &p->date_poste.jour,&p->date_poste.mois,&p->date_poste.annee);
                    break;
                }
        } while (rep != 'o' && rep != 'O' && rep != 'n' && rep != 'N');
}

void    affichage(employe p)
{
    printf("Nom : %s\n", p.nom);
    printf("Date embauche : %d %d %d\n", p.date_embauche.jour,p.date_embauche.mois,p.date_embauche.annee);
    printf("Date poste : %d %d %d\n", p.date_poste.jour,p.date_poste.mois,p.date_poste.annee);
}

int     main(void)
{
    employe         *entreprise;
    int             i,nb;

    do
        {
            printf("Nb d'employes dans l'entreprise (max %d) : ", EMPLOYE_MAX);
            scanf("%d", &nb);
        } while (nb <= 0 || nb > EMPLOYE_MAX);
    entreprise = (employe *) malloc(sizeof(employe) * nb);
    for(i = 0; i < nb; i++)
        {
            printf("\temployé n°%d\n", i+1);
            saisie(&entreprise[i]);
            printf("\n");
        }
    printf("******Affichage des employés******\n\n");
    for(i = 0; i < nb; i++)
        {
            printf("\temployé n°%d\n", i+1);
            affichage(entreprise[i]);
            printf("\n");
        }
    free(entreprise);
    return EXIT_SUCCESS;
}
