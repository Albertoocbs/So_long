/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:16:33 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/22 17:16:43 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
/*
Copie une chaine src vers dst avec taille size

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src); // Calcule longueur total de src
	if (size == 0)
		return (srclen); // Si size == 0, on  peut copier aucun caractère car
		// il y a pas d'espace dans dst. On retourne la longueur de src pour
		// informer combien d'espace serait nécessaire pour une copie complète
	i = 0;
	while (src[i] && i < (size - 1)) // On copie src dans dst, en laissant 
		// de la place pour ajouter le caractère '\0' à la fin
	{
		dst[i] = src[i]; // Copie chaque caractère de src dans dst
		i++;
	}
	dst[i] = '\0'; // Ajoute le caractère nul pour terminer dst
	return (srclen);
	// Retourne la longueur totale de src pour indiquer combien d'espace 
	// serait nécessaire pour copier src dans dst en entier, même si la copie 
	// est tronquée

	// Si la copie n'est pas tronquée (taille de dst suffisante pour src) :
		// src est entièrement copié dans dst.
		// la valeur retournée  confirme que size était suffisant
	// Si la copie est tronquée (taille de dst insuffisante pour src) :
		// dst ne contient qu'une partie de src
		// La valeur retournée indique la longueur totale de src, 
		//montrant combien espace aurait ete necess pour faire une copie compl.
}*/