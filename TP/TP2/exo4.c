#include <stdio.h>

int main()
{
    float somme;
    printf("Somme ? ");
    scanf("%f", &somme);
    somme*=100; // on multiplie par 100 pour pouvoir calculer au centime près sans avoir de virgule
    if (!((int)somme/50000 == 0)) //à chaque fois on vérifie que le rang n’est pas égal à 0 pour faire + propre
        printf("billets de 500€ : %d\n", (int)somme/50000);
    somme=(int)somme%50000;
    if (!((int)somme/10000 == 0))
        printf("billets de 100€ : %d\n", (int)somme/10000);
    somme=(int)somme%10000;
    if (!((int)somme/2000 == 0))
        printf("billets de 20€ : %d\n", (int)somme/2000);
    somme=(int)somme%2000;
    if (!((int)somme/1000 == 0))
        printf("billets de 10€ : %d\n", (int)somme/1000);
    somme=(int)somme%1000;
    if (!((int)somme/500 == 0))
        printf("billets de 5€ : %d\n", (int)somme/500);
    somme=(int)somme%500;
    if (!((int)somme/200 == 0))
        printf("pieces de 2€ : %d\n", (int)somme/200);
    somme=(int)somme%200;
    if (!((int)somme/100 == 0))
        printf("pieces de 1€ : %d\n", (int)somme/100);
    somme=(int)somme%100;
    if (!((int)somme/50 == 0))
        printf("pieces de 50cts : %d\n", (int)somme/50);
    somme=(int)somme%50;
    if (!((int)somme/20 == 0))
        printf("pieces de 20cts : %d\n", (int)somme/20);
    somme=(int)somme%20;
    if (!((int)somme/10 == 0))
        printf("pieces de 10cts : %d\n", (int)somme/10);
    somme=(int)somme%10;
    if (!((int)somme/5 == 0))
        printf("pieces de 5cts : %d\n", (int)somme/5);
    somme=(int)somme%5;
    if (!((int)somme/2 == 0))
        printf("pieces de 2cts : %d\n", (int)somme/2);
    somme=(int)somme%2;
    if (!((int)somme/1 == 0))
        printf("pieces de 1cts : %d\n", (int)somme/1);
    return 0;
}
