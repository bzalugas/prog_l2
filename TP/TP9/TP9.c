#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMP_MAX 100 //nb max d'employés ds la société
#define NOM 32 //à chaque fois max désiré +2 pour supprimer \n mais laisser assez de place
#define C_POSTAL 7

int total = 0; //variable globale pour connaitre le nb d'employés déjà entrés

typedef enum situation {
    libere,
    exempte,
    reforme,
    incorporable
} situation;

typedef enum sexe {
    M,
    F
} sexe;

typedef char nom[NOM];

typedef struct adresse {
    int num_rue;
    nom nom_rue;
    char code_postal[C_POSTAL];
    nom localite;
} adresse;

typedef struct employe {
    nom nom;
    nom prenom;
    adresse adr_emp;
    sexe s;
    union info_supp {
        situation sit_m;
        nom nom_j_f;
    } info_supp;
} employe;

void    read_str(char *str, int max)
{
    char buf[NOM];
    unsigned int len;

    fflush(stdin);
    fgets(buf, max, stdin);
    len = strlen(buf);
    if (len < max)
        buf[len - 1] = '\0';
    strcpy(str, buf);
}

char    *convertSituation(situation s)
{
    switch(s)
        {
        case libere: return ("libéré");
            break;
        case exempte: return ("exempté");
            break;
        case reforme: return ("réformé");
            break;
        case incorporable: return ("incorporable");
            break;
        default: return ("\0");
            break;
        }
}

void    saisieFiche(employe *p)
{
    fflush(stdin);
    printf("Nom : ");
    read_str(p->nom, NOM);

    fflush(stdin);
    printf("Prénom : ");
    read_str(p->prenom, NOM);

    fflush(stdin);
    printf("Adresse : \n");
    printf("\tNuméro de rue : ");
    scanf("%d", &p->adr_emp.num_rue);
    fflush(stdin);
    printf("\tNom de rue : ");
    read_str(p->adr_emp.nom_rue, NOM);
    fflush(stdin);
    printf("\tCode postal : ");
    read_str(p->adr_emp.code_postal, C_POSTAL);
    fflush(stdin);
    printf("\tLocalité : ");
    read_str(p->adr_emp.localite, NOM);

    do
        {
            fflush(stdin);
            printf("Sexe (Masculin = 0 / Féminin = 1) : ");
            scanf("%d", &p->s);
            switch(p->s)
                {
                case M:
                    do
                        {
                            fflush(stdin);
                            printf("Situation militaire (libéré=0, exempté=1, réformé=2, incorporable=3) : ");
                            scanf("%u", &p->info_supp.sit_m);
                        } while (p->info_supp.sit_m < 0 || p->info_supp.sit_m > 3);
                    break;
                case F:
                    fflush(stdin);
                    printf("Nom de jeune fille : ");
                    read_str(p->info_supp.nom_j_f, NOM);
                    break;
                default:
                    printf("%d n'est pas un choix valide.\n", p->s);
                    p->s = 2;
                    break;
                }
        } while (p->s == 2);
}

void    afficheFiche(employe p)
{
    printf("\tNom : %s\n", p.nom);

    printf("\tPrénom : %s\n", p.prenom);

    printf("\tAdresse : %d %s, %s, %s\n", p.adr_emp.num_rue,p.adr_emp.nom_rue,p.adr_emp.code_postal,p.adr_emp.localite);

    printf("\tSexe : ");


    switch (p.s)
        {
        case M:
            printf("Masculin\n");
            printf("\tSituation militaire : %s\n", convertSituation(p.info_supp.sit_m));
            break;
        case F:
            printf("Féminin\n");
            printf("\tNom de jeune fille : %s\n", p.info_supp.nom_j_f);
            break;
        }
}

void    add_emp(employe *e)
{
    int nb, i;

    if (total < EMP_MAX) //pour ne pas enregistrer + qu'il n'y a de place dispo
        {
            do
                {
                    fflush(stdin);
                    printf("Nb d'employés à entrer (max %d) : ", EMP_MAX - total);
                    scanf("%d", &nb);
                } while (nb < 0 || nb > EMP_MAX - total);
            total += nb;
            for(i = 0; i < nb; i++)
                {
                    printf("\n\t*** Fiche d'employé n°%d ***\n", i+1+(total - nb));
                    saisieFiche(&e[i+(total - nb)]);
                }
        }
    else
        printf("Le nombre maximum d'employés est déjà atteint.\n");
}

void    display_emp(employe *e)
{
    int i;

    for(i = 0; i < total; i++)
        {
            printf("\n\t*** Employé n°%d ***\n", i+1);
            afficheFiche(e[i]);
        }
}

void    del_emp(employe *e)
{
    int i, nb_emp;

    do
        {
            printf("\tEmployés inscrits : \n");
            for(i = 0; i < total; i++)
                printf("\tEmployé n°%d : %s %s\n", i+1, e[i].nom, e[i].prenom);
            printf("Employé à supprimer (numéro, -1 pour annuler) : ");
            scanf("%d", &nb_emp);
        } while (nb_emp != -1 && (nb_emp < 1 || nb_emp > total));
    if (nb_emp == -1)
        printf("Action annulée.\n");
    else
        {
            nb_emp--;
            for(i = nb_emp; i < total; i++)
                e[i] = e[i+1];
            total--;
            printf("l'employé n°%d a bien été supprimé.\n", nb_emp+1);
        }
}

void    choiceMenu(void)
{

    fflush(stdin);
    printf("\n\t****** Gestion des données du personnel ******\n");
    printf("\tInscrire de nouveaux employés : I\n");
    printf("\t\tAfficher les employés : A\n");
    printf("\t       Supprimer des employés : S\n");
    printf("\t\t\t      Quitter : Q\n");
    printf("choix > ");
}

int     main(void)
{
    employe *societe;
    char choice;

    if (!(societe = (employe *) malloc(sizeof(employe) * EMP_MAX)))
        {
            printf("erreur allocation memoire.\n");
            exit (0);
        }
    do
        {
            choiceMenu();
            scanf("%c", &choice);
            switch(choice)
                {
                case 'I':case 'i': add_emp(societe);
                    break;
                case 'A':case 'a': display_emp(societe);
                    break;
                case 'S':case 's': del_emp(societe);
                    break;
                case 'Q':case 'q':
                    break;
                default: printf("Choix incorrect.\n");
                    break;
                }
        } while (choice != 'Q' && choice != 'q');
    free(societe);
    return (0);
}
