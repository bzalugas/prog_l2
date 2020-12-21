#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

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

typedef enum fils {
    FG,
    FD
} fils;

noeud   *search_num(noeud *n, char e)
{
    noeud *tmp;

    if (n == NULL)
        return (NULL);
    if (n->etiquette == e)
        return (n);
    tmp = search_num(n->filsG, e);
    if (tmp != NULL)
        return (tmp);
    return (search_num(n->filsD, e));
}

noeud   *create_node(noeud *r)
{
    char name, choix;
    int f;
    noeud *n, *p;

    fflush(stdin);
    printf("Etiquette noeud : ");
    scanf("%c", &name);
    n = nouvNoeud(name);
    if (r != NULL)
        {
            fflush(stdin);
            printf("apres quel noeud inserer %c ?\n", name);
            printf("arbre actuel : \n");
            parcoursPrefixe(r);
            printf("\n>");
            fflush(stdin);
            scanf("%c", &choix);
            p = search_num(r, choix);
            do {
                fflush(stdin);
                printf("en tant que FG(0) ou FD(1) ? ");
                scanf("%d", &f);
            } while (f != FG && f != FD);

            if (f == FG)
                insererFG(n, r, p->num);
            else
                insererFD(n, r, p->num);
        }
    else
        r = n;
    fflush(stdin);
    printf("voulez-vous creer d'autres noeuds (o/n) ?");
    scanf("%c", &choix);
    if (choix == 'o')
        {
            if (r == NULL)
                create_node(n);
            else
                create_node(r);
        }
    return (r);
}

noeud   *create_tree(void)
{
    char name;

    fflush(stdin);
    printf("Etiquette de la racine (1 caractere) : ");
    scanf("%c", &name);
    noeud *r = nouvNoeud(name);
    return (r);
}

int     height_tree(int h, noeud *r)
{
    int g, d;

    if (r == NULL)
        return (h);
    g = height_tree(h+1, r->filsG);
    d = height_tree(h+1, r->filsD);
    if (g > d)
        return (g);
    else
        return (d);
}

int     nb_node(noeud *n, int nb)
{

    int g,d;

    if (n == NULL)
        return (0);
    g = nb_node(n->filsG, ++nb);
    d = nb_node(n->filsD, ++nb);
    return (g+d+1);
}

void    sym(noeud *n, FILE *fd)
{
    if (n == NULL)
        return;
    if (n->filsG == NULL && n->filsD == NULL)
        {
            fputc(n->etiquette, fd);
            return;
        }
    sym(n->filsG, fd);
    fputc(n->etiquette, fd);
    sym(n->filsD, fd);
}

char    *ordre(noeud *n, int nodes)
{
    char *tab;
    int i;
    FILE *fd;

    if (!(tab = malloc(sizeof(char) * nodes + 1)))
        {
            printf("erreur allocation memoire.\n");
            exit (0);
        }
    if ((fd = fopen("tmp","w")))
        {
            sym(n, fd);
            fclose(fd);
            if ((fd = fopen("tmp","r")))
                {
                    for(i = 0; i < nodes; i++)
                        tab[i] = fgetc(fd);
                    tab[nodes] = '\0';
                    fclose(fd);
                }
        }
    else
        printf("erreur ouverture du fichier.\n");
    return (tab);
}

void    parcoursSym(noeud *n)
{
    if (n == NULL)
        return;
    if (n->filsG == NULL && n->filsD == NULL)
        {
            afficher(n->etiquette);
            return;
        }
    parcoursSym(n->filsG);
    afficher(n->etiquette);
    parcoursSym(n->filsD);
}

int     max_node(int height)
{
    if (height == 1)
        return (1);
    return (max_node(height - 1) * 2 + 1);
}

#define SG '/'
#define SD '\\'
#define ESP '.'

int    indRacine(noeud *r, char *tab)
{
    int i;
    for(i = 0; tab[i]; i++)
        {
            if (tab[i] == r->etiquette)
                return (i);
        }
    return (-1);
}

char    currentChar(char *tab, int r, int i, int w)
{
    static int nb;

    if (i == 0 || i == w)
        {
            if (nb % 2 == 0)
                return (tab[r + nb++]);
            return (tab[r - nb++]);
        }
    if (nb++ % 2 == 0)
        return (SD);
    return (SG);
}

void    afficheStyle(noeud *r, char *tab)
{
    int width, len, len2, height, nbspace, nbligne, level, totligne;
    int i, j, k, l;
    int racine = indRacine(r, tab);

    height = height_tree(0, r);
    len = max_node(height);
    len2 = (len + 1) / 2;
    width = len2 + (len2 / 2) * 3 + (len2 / 2) - 1;
    nbspace = width / 2;
    nbligne = width / 2;
    totligne = width / 2;
    level = 0;
    for(i = 0; i < totligne; i++)
        {
            nbligne /= 2;
            for(k = 0; k < nbligne; k++)
                {
                    l = pow(2,level);
                    while (l > 0)
                        {
                            for(j = nbspace; j > k; j--)
                                {
                                    afficher(ESP);
                                }
                            afficher(currentChar(tab, racine, i, nbligne));
                            if (k > 0)
                                {
                                    for(;j > 0; j--)
                                        afficher(ESP);
                                    afficher(currentChar(tab, racine, k, nbligne));
                                }
                            l--;
                        }
                    printf("\n");
                }
            level++;
            i = k;
        }
}

void    clean(noeud *r)
{
    if (r->filsG != NULL)
        clean(r->filsG);
    if (r->filsD != NULL)
        clean(r->filsD);
    free(r);
}

void    choiceMenu(void)
{
    char c;
    char *tab;
    int nb;
    int height;
    noeud *r = NULL;

    do {
        fflush(stdin);
        printf("\n****** ARBRES BINAIRES ******\n");
        printf("\nCreer un arbre : C\n");
        printf("Creer un noeud : N\n");
        printf("Afficher l'arbre (parcours prefixe) : A\n");
        printf("Afficher l'arbre (parcours symetrique) : S\n");
        printf("Afficher l'arbre (dessin) : D\n");
        printf("clean : E\n");
        printf("Quitter : Q\n>");
        scanf("%c", &c);
        switch (c)
            {
            case 'C':case'c': r = create_tree();
                break;
            case'N':case'n': r = create_node(r);
                break;
            case 'A':case'a':
                if (r != NULL)
                    {
                        printf("\n");
                        parcoursPrefixe(r);
                        height = height_tree(0,r);
                        printf("\nTaille = %d\nnoeuds presents = %d\nnoeuds max = %d\n", height,nb_node(r,0), max_node(height));
                    }
                else
                    printf("arbre vide.\n");
                break;
                case 'S':case's':
                if (r != NULL)
                    {
                        nb = nb_node(r,0);
                        tab = ordre(r, nb);
                        printf("\n");
                        //parcoursSym(r);
                        printf("%s\n", tab);
                        height = height_tree(0,r);
                        printf("\nTaille = %d\nnoeuds max = %d\n", height, max_node(height));
                    }
                else
                    printf("arbre vide.\n");
                break;
            case'D':case'd':
                nb = nb_node(r,0);
                tab = ordre(r, nb);
                afficheStyle(r, tab);
                break;
            case'E':case'e': clean(r); r = NULL;
                break;
            }
    } while (c != 'Q' && c != 'q');
    if (r != NULL)
        clean(r);
}

int     main(void)
{
    choiceMenu();
    return EXIT_SUCCESS;
}

/*

.....A
..../.\
.../...\
..B.....C
./.\.../.\
D...E.F...G


..A
./.\
B...C



...........A
........../.\
........./...\
......../.....\
......./.......\
....../.........\
.....B...........C
..../.\........./.\
.../...\......./...\
..D.....E.....F.....G
./.\.../.\.../.\.../.\
H...I.J...K.L...M.N...O












.......................A
....................../.\
...................../...\
..................../.....\
.................../.......\
................../.........\
................./...........\
................/.............\
.............../...............\
............../.................\
............./...................\
............/.....................\
...........B.......................C
........../.\...................../.\
........./...\.................../...\
......../.....\................./.....\
......./.......\.............../.......\
....../.........\............./.........\
.....D...........E...........F...........G
..../.\........./.\........./.\........./.\
.../...\......./...\......./...\......./...\
..H.....I.....J.....K.....L.....M.....N.....O
./.\.../.\.../.\.../.\.../.\.../.\.../.\.../.\
P...Q.R...S.T...U.V...W.X...Y.Z...A.B...C.D...E


     .
    ...
   .....
  .......
 .........
...........
 .........
  .......
   .....
    ...
     .
*/
