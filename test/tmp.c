#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void noteclasse(int *tableau,int nombre)
{
    int i;
    for(i=0;i<nombre;i++)
    {
        printf("Ecrivez les notes un par un");
        scanf("%d",&tableau[i]);
    }
}

int note_moyenne(int *tableau,int nombre)
{
    int i,somme=0;
    for(i=0;i<nombre;i++)
    {
        somme = somme + tableau[i];
    }
    somme = somme / nombre;
    tableau[nombre+1]=somme;
    return somme;
}

void note_bassehaute(int *tableau,int nombre,int *basse,int haute)
{
    int i;
    for(i=0;i<nombre;i++)
    {
        if (tableau[i]<basse)
        {
            basse=tableau[i];
        }
        if (tableau[i]>haute)
        {
            *haute=tableau[i];
        }
    }
    tableau[nombre+2]=basse;
    tableau[nombre+3]=haute;

}

int main()
{
    int nombre,taille_tab,somme,basse=0,haute=0;
    int liste_eleve=NULL;
    printf("Le nombre d eleves dans la classe ?");
    scanf("%d",&nombre);
    taille_tab = nombre + 3;
    liste_eleve=malloc(sizeof(int)taille_tab);
    if (liste_eleve==0)
        exit(1);
    noteclasse(&liste_eleve,nombre);
    somme=note_moyenne(&liste_eleve,nombre);
    note_bassehaute(&liste_eleve,nombre,&basse,&haute);
    printf("La moyenne de la classe est de %d\n",somme);
    printf("La note la plus basse est %d, la note la plus haute est %d \n",basse,haute);
    printf("voici le tableau");
    int i;
    for (i=0;i<taille_tab;i++)
    {
        printf("%d  ",liste_eleve[i]);
    }
    free (liste_eleve);
    return 0;
}
