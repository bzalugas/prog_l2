//tp11_exo1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x,
        y;
} point;

typedef struct cellule cellule;
struct cellule {
    point contenu;
    cellule *prev;
    cellule *next;
};

cellule     *nouvCel(point p)
{
    cellule *cel;
    if (!(cel = malloc(sizeof(cellule *))))
        {
            printf("erreur allocation memoire.\n");
            return NULL;
        }
    cel->contenu.x = p.x;
    cel->contenu.y = p.y;
    cel->prev = NULL;
    cel->next = NULL;
    return (cel);
}

void        insererCellule(int pl, cellule *cel, cellule *liste)
{
    int i;
    cellule *rang = liste;
    for (i = 0; i < pl; i++)
        rang = rang->next;
    cel->prev = rang;
    if (rang->next != NULL)
        {
            cel->next = rang->next;
            rang->next->prev = cel;
        }
    rang->next = cel;
}

void        supprimerCellule(int pl, cellule *liste)
{
    int i;
    cellule *rang = liste;
    for (i = 0; i < pl; i++)
        rang = rang->next;
    if (rang->prev != NULL)
        rang->prev->next = rang->next;
    if (rang->next != NULL)
        rang->next->prev = rang->prev;
    free(rang);
}

void        afficher(cellule *liste)
{
    cellule *rang;
    rang = liste;
    int i=0;
    while (rang->next != NULL)
        {
            printf("%d:(%d, %d), ", i, rang->contenu.x, rang->contenu.y);
            rang = rang->next;
            i++;
        }
    printf("%d:(%d, %d)\n\n", i, rang->contenu.x, rang->contenu.y);
}

cellule     *create(void)
{
    point pt;
    cellule *nouv;
    printf("\nCreation de la liste\n");
    printf("x = ");
    fflush(stdin);
    scanf("%d", &pt.x);
    printf("y = ");
    fflush(stdin);
    scanf("%d", &pt.y);
    nouv = nouvCel(pt);
    return (nouv);
}

void        insert(cellule *liste)
{
    point pt;
    int pl;
    cellule *cel;
    printf("\nInsertion cellule\n");
    printf("x = ");
    fflush(stdin);
    scanf("%d", &pt.x);
    printf("y = ");
    fflush(stdin);
    scanf("%d", &pt.y);
    cel = nouvCel(pt);
    afficher(liste);
    printf("Numero de la cellule apres laquelle inserer (%d, %d) \n", pt.x, pt.y);
    printf("\t> ");
    fflush(stdin);
    scanf("%d", &pl);
    insererCellule(pl, cel, liste);
    printf("Cellule correctement inseree.\n");
}

void        supp(cellule *liste)
{
    int pl;
    printf("\nSuppression de cellule\n");
    afficher(liste);
    printf("Numero cellule a supprimer\n");
    printf("> ");
    fflush(stdin);
    scanf("%d", &pl);
    supprimerCellule(pl, liste);
    printf("Cellule correctement supprimee.\n");
}

void        suppTout(cellule *liste)
{
    if (liste->next != NULL)
        suppTout(liste->next);
    free(liste);
    return;
}

void        menu(void)
{
    char c;
    cellule *liste;
    do {
        printf("creer liste : C\n");
        printf("inserer cellule : i\n");
        printf("supprimer cellule : s\n");
        printf("afficher liste : a\n");
        printf("Quitter: q\n");
        fflush(stdin);
        scanf("%c", &c);
        switch (c) {
        case 'c':
            if (liste == NULL)
                liste = create();
            else
                printf("liste deja cree.\n");
            break;
        case 'i':
            if (liste != NULL)
                insert(liste);
            else
                printf("liste pas encore cree.\n");
            break;
        case 's':
            if (liste != NULL)
                supp(liste);
            else
                printf("Liste vide, rien a supprimer.\n");
            break;
        case 'a':
            if (liste != NULL)
                afficher(liste);
            else
                printf("Liste vide.\n");
            break;
        }
    } while (c != 'q');
    if (liste != NULL)
        suppTout(liste);
}

int         main(void)
{
    menu();
    return (0);
}
