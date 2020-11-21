#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum situation {
    nouveau,
    ancien,
    fin
} situation;

typedef struct personne {
    char nom[10];
    situation sit;//nouveau ou ancien ou fin
} personne;

void    afficher(personne *p)
{
    int i;

    for(i = 0; i < 2; i++)
        {
            printf("nom : %s\n", p[i].nom);
            printf("situation : %u\n", p[i].sit);
        }

}

int main()
{
    personne pers[2] = {{"bastien", ancien}, {"salut", nouveau}};
    afficher(pers);
    pers[0] = pers[1];
    afficher(pers);
    return (0);
}
