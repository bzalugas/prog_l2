#include <stdio.h>

#define PI 3.1415

int main (void)
{
    float c, rayon, aire_c, aire_n, circonf;

    printf("cote du carre ? ");
    scanf("%f", &c);
    aire_c = c*c;
    printf("aire carre = %.2f\n", aire_c);
    rayon = c/2;
    printf("rayon = %.2f\n", rayon);
    circonf = PI*rayon*rayon;
    printf("circonf = %.2f\n", circonf);
    aire_n = aire_c - circonf;
    printf("aire surface noircie = %.2f", aire_n);
    return (0);
}
