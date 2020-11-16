#include <stdio.h>

int main()
{
    unsigned char jour;
    unsigned int tmp;
    printf("jour : ");
    fflush(stdin);
    scanf("%d", &tmp);
    jour = tmp;
    printf("jour = %d\n", jour);
    return (0);
}
