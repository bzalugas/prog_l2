/*programme de calcul de circonférence*/

#include <stdio.h>

float   circonference(float rayon)
    {
        float pi;
        float circon;
        pi = 3.1415;
        circon = 2 * pi * rayon;
        return (circon);
    }

int     main(void)
    {
        float r;
        int i;
        int n;
        n = 5;
        /* saisie par l'utilisateur de n rayons et calcul des n curconferences correspondantes */
        for (i = 0; i < n; i++)
            {
                printf("Saisie du rayon n° %d \n", i);
                scanf ("%f", &r);
                printf ("La circonference est de : %.2f\n", circonference(r));
            }
        return (1);
    }
