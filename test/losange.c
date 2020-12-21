/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   losange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 07:38:52 by bzalugas          #+#    #+#             */
/*   Updated: 2020/12/15 07:48:00 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
    int taille;
    int i, j;

    printf("taille losange ? ");
    scanf("%d", &taille);

    for(i = 0; i < taille; i++)
        {
            for(j = taille; j > i; j--)
                {
                    printf(".");
                }
            printf("*");
            for(; j > 0; j--)
                printf(".");
            printf("*");
            printf("\n");
        }
}
