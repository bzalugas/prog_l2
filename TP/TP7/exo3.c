#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    char *jour[] = {"numéro incorrect", "lundi", "mardi", "mercredi", "jeudi",
        "vendredi", "samedi", "dimanche"};

    printf("Nb entre 1 et 7 : ");
    scanf("%d", &num);
    if (num > 0 && num < 8)
        printf("%d = %s\n", num, jour[num]);
    else
        printf("%s\n", jour[0]);
    return (0);
}
