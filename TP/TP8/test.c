#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 31

typedef struct personne {
    char nom[MAX];
    int age;
} personne;

void    read_str(char *str)
{
    printf("read\n");
    char buffer[MAX];
    //récupération entrée standart dans un buffer
    fgets(buffer, MAX, stdin);
    /* if (!(str = (char *) malloc(sizeof(char) * (strlen(buffer)+1)))) */
    /*     { */
    /*         printf("erreur allocation mémoire"); */
    /*         exit (0); */
    /*     } */
    printf("test : %s\n", buffer);
    //supression du \n
    if (strlen(buffer) < MAX)
        buffer[strlen(buffer) - 1] = '\0';
    //copie dans la chaine
    strcpy(str, buffer);
}

int main()
{
    personne *p;
    if(!(p = (personne *) malloc(sizeof(personne))))
        return (1);
    fflush(stdin);
    printf("prenom : ");
    read_str(p->nom);
//    scanf("%s", p.nom);
    fflush(stdin);
    printf("age : ");
    scanf("%d", &p->age);
    printf("%s a %d ans.\n", p->nom, p->age);
    free(p);
    return (0);
}
