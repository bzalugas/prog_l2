//TP6_exo2_v2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

char    *read_str(void)
{
    char *str;
    char buffer[MAX];
    int len;

    fgets(buffer, MAX, stdin); //on utilise un buffer temporaire
    // allocation dynamique pour garder la chaine dans le tas
    len = strlen(buffer);
    if (buffer[len-1] == '\n')
        buffer[len-1] = '\0'; // pour supprimer le \n pour l'affichage
    if (!(str = (char *) malloc(sizeof(char) * (strlen(buffer)+1))))
        {
            printf("erreur allocation mémoire");
            exit (0);
        }
    strcpy(str, buffer); //on copie le contenu du buffer temporaire dans
                         //le tableau du tas
    return (str); // on retourne l'adresse du tableau dans le tas
}

int     roman_to_nb(char c)
{
    char cbase[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int ibase[] = {1, 5, 10, 50, 100, 500, 1000};
    int i;

    if (c != '\0')
        {
            for(i = 0; i < 7; i++)
                if (c == cbase[i])
                    return (ibase[i]);
            printf("erreur caractere : %c incorrect.\n", c);
        }
    return (0);
}

int     convert_romans_to_nb(char *romans)
{
    int i, result=0;

    for (i = 0; romans[i]; i++)
        {
            if (roman_to_nb(romans[i+1]) > roman_to_nb(romans[i]))
                result -= roman_to_nb(romans[i]);
            else
                result += roman_to_nb(romans[i]);
        }
    return (result);
}

void    ft_romans_digits(void)
{
    char *nb_in;
    int nb_out;

    printf ("Chiffres romains à convertir (maximum %d chiffres) : \n\n\t", MAX - 1);
    nb_in = read_str(); //on récupère le nb à convertir
    nb_out = convert_romans_to_nb(nb_in); // on le convertit
    printf("\n%s = %d\n\n", nb_in, nb_out); // on affiche le résultat
}

int     main(void)
{
    char choice;
//menu affichage
    do
        {
            fflush(stdin);
            printf("********Convertisseur de chiffres romains********\n");
            printf("\tLire un nombre en chiffre romains : R\n");
            printf("\t\t\t\t  Quitter : Q\n");
            scanf("%c%*c", &choice);
            if (choice == 'R' || choice == 'r')
                ft_romans_digits();
        } while (choice != 'Q' && choice != 'q');
    return EXIT_SUCCESS;
}
