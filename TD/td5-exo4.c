#include <stdio.h>
#include <stdlib.h>

void hanoi(int nb, int deb, int fin, int inter)
{
    if (nb > 0)
        {
            hanoi(nb -1, deb, inter, fin);
            printf("deplacer disque de %d vers %d\n", deb, fin);
            hanoi(nb -1, inter, fin, deb);
        }
}

int main(int argc, char **argv)
{
    int nb;

    (void)argc;
    nb = atoi(argv[1]);
    hanoi(nb, 1, 3, 2);
}
