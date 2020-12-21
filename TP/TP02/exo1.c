#include <stdio.h>

/* V1
   int main(void)
   {
   int a,b,c,d,e;

   printf("entrez 4 entiers : ");
   fflush(stdin);
   scanf("%d", &a);
   scanf("%d", &b);
   scanf("%d", &c);
   scanf("%d", &d);
   e = a+b+c+d;
   printf("Somme = %d\n", e);
   return (0);
   }*/

int main(void)
{
    int tmp, result=0, i=0;

    printf("entrez 4 entiers : ");
    while (i < 4)
        {
            scanf("%d", &tmp);
            result += tmp;
            i++;
        }
    printf("Somme = %d\n", result);
    return (0);
}
