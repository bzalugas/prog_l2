#include <stdio.h>

int main()
{
    float r1, r2;
    char choix;

    printf("Entrez votre premier réel : ");
    scanf("%f", &r1);
    printf("Entrez votre second réel : ");
    scanf("%f", &r2);
    do
        {
            printf("\nAddition   A\nSoustraction   S\nMultiplication  M\nDivision  D\nQuitter  Q\n");
            printf("Votre choix ? ");
            scanf("%*c%c", &choix);
            printf("\n");
            switch (choix)
                {
                case 'm':case 'M' : printf(" %.2f * %.2f = %.2f\n", r1, r2, r1 * r2);
                    break;
                case 'a':case 'A' : printf("%.2f + %.2f = %.2f\n", r1, r2, r1 + r2);
                    break;
                case 's':case 'S' : printf("%.2f - %.2f = %.2f\n", r1, r2, r1 - r2);
                    break;
                case 'd':case 'D' : printf("%.2f / %.2f = %.2f\n", r1, r2, r1 / r2);
                    break;
                case 'q':case 'Q' :
                    break;
                default : printf("%c n'est pas un choix valide.\n", choix);
                }
        }
    while (choix!='q'&&choix!='Q');
    return(0);
}
