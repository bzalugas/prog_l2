#include <stdio.h>

#define MAX 20

int main(void)
{
    int tab[MAX], end_tab, i;

    do
        {
            printf("NB valeurs (max = %d) ? ", MAX);
            scanf("%d", &end_tab);
        } while (end_tab > MAX || end_tab <= 0);
    for (i = 0; i < end_tab; i++)
        {
            printf("nb n°%d ? ", i+1);
            scanf("%d", &tab[i]);
        }
    printf("\n");
    for (i = 0; i < end_tab; i++)
        printf("nb n°%d = %d\n", i+1, tab[i]);
    return (0);
}
