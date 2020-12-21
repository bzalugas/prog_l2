#include <stdio.h>
#include <stdlib.h>

typedef struct noeud {
    char etiquette;
    int num;
    struct noeud *pere, *filsG, *filsD;
} noeud;

noeud   *nouvNoeud(char carac)
{
    noeud *nouv;
    static int numero;

    if (!(nouv = malloc(sizeof(noeud))))
        {
            printf("erreur allocation memoire.\n");
            exit (0);
        }
    nouv->etiquette = carac;
    nouv->num = numero++;
    nouv->pere = NULL;
    nouv->filsG = NULL;
    nouv->filsD = NULL;
    return (nouv);
}

noeud   *rechercheNoeud(noeud *n, int numNoeud)
{
    noeud *tmpNoeud;

    if (n == NULL)
        return (NULL);
    if (n->num == numNoeud)
        return(n);

    tmpNoeud = rechercheNoeud(n->filsG, numNoeud);
    if (tmpNoeud != NULL)
        return(tmpNoeud);

    return(rechercheNoeud(n->filsD, numNoeud));
}

void    insererFG(noeud *newnoeud, noeud *arbre, int numNoeud)
{
    noeud *insertion = rechercheNoeud(arbre, numNoeud);

    if (insertion == NULL)
        {
            printf("insererFG : pas de noeud avec le numero %d.\n", numNoeud);
            return;
        }
    newnoeud->filsG = insertion->filsG;
    newnoeud->pere = insertion;
    insertion->filsG = newnoeud;
}

void    insererFD(noeud *newnoeud, noeud *arbre, int numNoeud)
{
    noeud *insertion = rechercheNoeud(arbre, numNoeud);

    if (insertion == NULL)
        {
            printf("insererFD : pas de noeud avec le numero %d.\n", numNoeud);
            return;
        }
    newnoeud->filsD = insertion->filsD;
    newnoeud->pere = insertion;
    insertion->filsD = newnoeud;
}

void    afficher(char c)
{
    printf("%c ", c);
}

void    parcoursPrefixe(noeud *n)
{
    if (n == NULL)
        return;
    afficher(n->etiquette);
    parcoursPrefixe(n->filsG);
    parcoursPrefixe(n->filsD);
}
