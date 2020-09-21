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

	printf("Introduisez la date (jour mois année) : ");
	donnees = scanf("%d%d%d", &j,&m,&a);
	printf("Données correctement lues : %d\n", donnees);
	printf("/*****Affichage de la date saisie ****/\n");
	printf("Jour : %d\nMois : %d\nAnnée : %d\n", j,m,a);
	return (0);
}
