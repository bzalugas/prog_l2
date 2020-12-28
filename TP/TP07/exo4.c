#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 31 //verbe le + long en français = 31 lettres

char    *read_str(void)
{
    char buf[LEN];
    char *str;
    int length;

    fgets(buf, LEN, stdin);
    length = strlen(buf);
    //suppression \n
    if (length < LEN)
        buf[length - 1] = '\0';
    if (!(str = (char *) malloc(sizeof(char) * length)))
        {
            printf("probleme allocation memoire\n");
            exit (0);
        }
    strcpy(str, buf);
    return (str);
}

int     saisieVerbe(char **verb)
{
    int length;

    fflush(stdin);
    printf("Verbe du 1er groupe à conjuguer : ");
    *verb = read_str();
    length = strlen(verb[0]);
    if (verb[0][length - 2] == 'e' && verb[0][length - 1] == 'r')
        return (1);
    else
        return (0);
}

void    conjugaison(char *verb)
{
    char *sujet[] = {"Je", "Tu", "Il", "Nous", "Vous", "Ils"};
    char *term[] = {"e", "es", "e", "ons", "ez", "ent", "eons"};
    int i, end = strlen(verb) - 2;

    verb[end] = '\0';
    printf("\t*** Conjugaison ***\n");
    for(i = 0; i < 6; i++)
        {
//            dans le cas d'un verbe irrégulier (non demandé dans la consigne)
            if (i == 3)
                {
                    if (verb[end - 1] == 'g')
                        printf("\t%s %s%s\n", sujet[i], verb, term[6]);
                }
//
            else
                printf("\t%s %s%s\n", sujet[i], verb, term[i]);
        }
}

int     main(void)
{
    char *verb=NULL;
    int fg; //pour récupérer et vérifier la sortie de saisieVerbe sans relancer la fonction

    do
        fg = saisieVerbe(&verb);
    while (fg == 0);
    conjugaison(verb);
    free(verb);
    return (0);
}
