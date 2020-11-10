//tp6_exo1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11

char *read_str(void)
{
    char *str;
    char buffer[MAX];
    fgets(buffer, MAX, stdin);
    if (!(str = (char *) malloc(sizeof(char) * (strlen(buffer)+1))))
        {
            printf("erreur allocation mémoire");
            exit (0);
        }
    strcpy(str, buffer);
    return (str);
}

char *str_invert(const char *str)
{
    int i;
    char *result;

    if(!(result = (char *) malloc(sizeof(char) * (strlen(str) + 1))))
        {
            printf("erreur allocation memoire");
            exit (0);
        }
    strcpy(result, str);
    i = 0;
    while (str[i])
        {
            if (result[i] >= 'A' && result[i] <= 'Z')
                result[i] += 32;
            else if (result[i] >= 'a' && result[i] <= 'z')
                result[i] -= 32;
            i++;
        }
    return (result);
}

int main()
{
    char *str;
    char *resultat;

    printf("chaine de caractère (max = %d) ?\n", MAX-1);
    str = read_str();
    resultat = str_invert(str);
    printf("chaine debut : %s\n", str);
    free(str);
    printf("chaine fin : %s\n", resultat);
    free(resultat);
    return EXIT_SUCCESS;
}

//version passage par adresse

/*void    read_str(char **str)
{
    char buffer[MAX];
    fgets(buffer, MAX, stdin);
    if (!(*str = (char *) malloc(sizeof(char) * (strlen(buffer)+1))))
        {
            printf("erreur allocation mémoire");
            exit (0);
        }
    strcpy(*str, buffer);
}

void    str_invert(char **result, const char *str)
{
    int i;

    if(!(*result = (char *) malloc(sizeof(char) * (strlen(str) + 1))))
        {
            printf("erreur allocation memoire");
            exit (0);
        }
    strcpy(*result, str);
    i = 0;
    while (str[i])
        {
            if (result[0][i] >= 'A' && result[0][i] <= 'Z')
                result[0][i] += 32;
            else if (result[0][i] >= 'a' && result[0][i] <= 'z')
                result[0][i] -= 32;
            i++;
        }
}

int     main()
{
    char *str;
    char *resultat;

    printf("chaine de caractère (max = %d) ?\n", MAX);
    read_str(&str);
    str_invert(&resultat, str);
    printf("chaine debut : %s\n", str);
    free(str);
    printf("chaine fin : %s\n", resultat);
    free(resultat);
    return EXIT_SUCCESS;
}*/
