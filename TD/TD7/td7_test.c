#include <stdio.h>
#include <string.h>

int main()
{
    char *ptab;
    char tab[] = "QW";
    char ch1[]="Bonjour";
    char ch2[15];
    strcpy(ch2, ch1);
    ptab = ch2;
    strcpy(ptab, "ASDFGHJKL");

    printf("tab: %s         ptab: %s\n", tab, ptab);
    printf("tab: %c         ptab: %c\n", tab[0], ptab[0]);
    printf("tab: %c         ptab: %c\n", tab[1], ptab[1]);
    printf("tab: %c         ptab: %c\n", *(tab+1), *(ptab+1));
    printf("tab: %c         ptab: %c\n", *tab+1, *ptab+1);
}
