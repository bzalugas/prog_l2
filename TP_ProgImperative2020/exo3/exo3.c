/*
 * exo3.c
 *
 *  Created on: 21 sept. 2020
 *      Author: bastien
 */

#include <stdio.h>

int main(void)
{
	int j,m,a,donnees;
	char tmp;

	printf("Introduisez la date (jour mois année) : ");
	donnees = scanf("%d%c%d%c%d", &j, &tmp, &m, &tmp, &a);
	printf("Données correctement lues : %d\n", donnees - 2);
	printf("/*****Affichage de la date saisie ****/\n");
	printf("Jour : %d\nMois : %d\nAnnée : %d\n", j,m,a);
	return (0);
}
