#include <stdio.h>

int main()
{
    int var1, var2;
    printf("Entrez votre division (format entier/entier) : ");
    fflush(stdout);
    scanf("%d/%d", &var1, &var2);
    printf("Le quotient vaut %d, le reste vaut %d et le quotient rationnel vaut %.2f.\n", var1/var2, var1%var2, ((float)var1)/((float)var2));
    return (0);
}
