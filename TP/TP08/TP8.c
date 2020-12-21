#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM_MAX 30
#define EMPLOYE_MAX 5

typedef struct date {
    char    jour[3];
    char    mois[3];
    char    annee[5];
} date;

typedef struct employe {
    char    nom[NOM_MAX];
    date    dte_emb;
    date    dte_pste;
} employe;

void    read_str(char *str)
{
    char buffer[NOM_MAX];
    fgets(buffer, NOM_MAX, stdin);
    //suppression du \n
    if (strlen(buffer) < NOM_MAX)
        buffer[strlen(buffer) - 1] = '\0';
    strcpy(str, buffer);
}

void    saisie(employe *p)
{
    char rep;
    fflush(stdin);
    printf("Nom : ");
    read_str(p->nom);
//    scanf("%s", p->nom);
    fflush(stdin);
    printf("Date embauche (jj mm aaaa) : ");
    scanf("%c%c %c%c %c%c%c%c", &p->dte_emb.jour[0],&p->dte_emb.jour[1],&p->dte_emb.mois[0],&p->dte_emb.mois[1],&p->dte_emb.annee[0],&p->dte_emb.annee[1],&p->dte_emb.annee[2],&p->dte_emb.annee[3]);
    p->dte_emb.jour[2] = '\0';
    p->dte_emb.mois[2] = '\0';
    p->dte_emb.annee[4] = '\0';
    do
        {
            fflush(stdin);
            printf("Date poste = date embauche ? (O/N) : ");
            scanf("%c", &rep);
            switch(rep)
                {
                case 'O':case'o':
                    p->dte_pste = p->dte_emb;
                    break;
                case 'N':case'n':
                    printf("Date poste (jj mm aa) : ");
                    fflush(stdin);
                    scanf("%c%c %c%c %c%c%c%c", &p->dte_pste.jour[0],&p->dte_pste.jour[1],&p->dte_pste.mois[0],&p->dte_pste.mois[1],&p->dte_pste.annee[0],&p->dte_pste.annee[1],&p->dte_pste.annee[2],&p->dte_pste.annee[3]);
                    break;
                }
        } while (rep != 'o' && rep != 'O' && rep != 'n' && rep != 'N');
}

void    affichage(employe p)
{
    printf("Nom : %s\n", p.nom);
    printf("Date embauche : %s %s %s\n", p.dte_emb.jour,p.dte_emb.mois,p.dte_emb.annee);
    printf("Date poste : %s %s %s\n", p.dte_pste.jour,p.dte_pste.mois,p.dte_pste.annee);
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
