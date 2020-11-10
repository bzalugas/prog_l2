#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 11

char    *read_str(void)
{
    char *str;
    char buffer[MAX];

    fgets(buffer, MAX, stdin); //on utilise un buffer temporaire
    // allocation dynamique pour garder la chaine dans le tas
    if (!(str = (char *) malloc(sizeof(char) * (strlen(buffer)+1))))
        {
            printf("erreur allocation mémoire");
            exit (0);
        }
    int i;
    int len = strlen(buffer);
    if (len < MAX-1)
        buffer[len-1] = '\0';
    printf("buff = %s", buffer);
    printf(" taille buff = %d", len);

    /* for(i=0;i<len;i++) */
    /*     if (buffer[i] == '\n') */
    /*         printf("RANG = %d\n", i); */
    /* if (strlen(buffer) < MAX) */
    /*     buffer[strlen(buffer) - 1] = '\0'; */
    /*                                    //avoir de bug d'affichage */
    strcpy(str, buffer); //on copie le contenu du buffer temporaire dans
                         //le tableau du tas
    return (str); // on retourne l'adresse du tableau dans le tas
}

int main()
{
    char *str;
    printf("entrez chaine : ");
    str = read_str();
    int nb = strlen(str);
    printf("chaine = %s taille = %d, str[%d] = %c\n", str, nb, nb-1, str[nb-1]);
    return EXIT_SUCCESS;
}
