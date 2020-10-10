#include <stdio.h>

int main(void)
{
    int x,p,n,nb,i;

    printf("x ? ");
    scanf("%d", &x);
    printf("p ? ");
    scanf("%d", &p);
    printf("n ? ");
    scanf("%d", &n);
    nb = 1;
    for(i=0; i < n; i++)
        nb *= 2;
    nb -= 1;
    nb = nb << (p-1);
    nb = nb ^ x;
    printf("nombre de depart = %d, nombre apres inversion des %d bits au rang %d = %d", x,n,p,nb);
    return (0);
}
