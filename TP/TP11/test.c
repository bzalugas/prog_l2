#include <stdio.h>
#include <stdlib.h>

typedef struct cel cel;
struct cel {
    int nb;
    cel *n;
    cel *p;
};

int main()
{
    cel *premier;
    premier = malloc(sizeof(cel));
    premier->nb = 1;
    premier->n = NULL;
    premier->p = NULL;
    cel *deux;
    deux = malloc(sizeof(cel));
    deux->nb = 2;
    deux->n = NULL;
    deux->p = premier;
    premier->n = deux;
    cel *trois;
    trois = malloc(sizeof(cel));
    trois->nb = 3;
    trois->n = NULL;
    trois->p = deux;
    deux->n = trois;
    cel *tmp;
    tmp = premier;
    tmp = tmp->n;
    tmp = tmp->n;
    tmp = tmp->n;
    tmp = tmp->n;
    free(premier);
    free(deux);
    free(trois);
}
