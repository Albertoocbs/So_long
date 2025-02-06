/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:55:18 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/22 17:02:04 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2len;
	size_t	i;
	size_t	j;

	s2len = ft_strlen(s2);
	if (s1 == s2 || s2len == 0)
		return ((char *)s1);
	i = 0;
	while (i < n && s1[i])
	{
		j = 0;
		while (s1[i + j] && s2[j] && (i + j) < n && s1[i + j] == s2[j])
		{
			j++;
			if (j == s2len)
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (0);
}
/*
	s1 = Chaine de caractère ou effectuer la recherche
	s2 = Chaine de caractère a trouver dans la chaine
	
	Retourne un pointeur vers le début de la première occurrence de s2 complète
	dans s1 si elle est trouvée dans la limite de n caractères, sinon NULL

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2len;
	size_t	i;
	size_t	j;

	s2len = ft_strlen(s2); // Calcule longueur totale de s2
	if (s1 == s2 || s2len == 0) // Si les chaines sont pareil ou si s2 est vide
		return ((char *)s1); // Retourne s1 casté en char car char est attendue 
	i = 0;
	while (i < n && s1[i]) //Parcourt chaque caractere de s1 jusqua n caractere
	{
		j = 0;

		//Parcourt chaque caractère de s2 et compare avec une sous-chaîne de s1
		// depuis l'index i, en restant dans la limite de n
		// s1[i + j] = sous chaine de s1, tant que on attaint pas valeur nul
		// s2[j] = tant que on atteint pas la valeur nul dans s2
        // (i + j) < n = tant que s1[i + j] est dans la limite de n caractères
        //s1[i + j] == s2[j] = compare chaque carac de s2 avec la souschaine s1
		while (s1[i + j] && s2[j] && (i + j) < n && s1[i + j] == s2[j])
		{
			j++;

			/// Si j atteint s2len (longueur totale de s2),
			//cela signifie que tous les caractères de s2 ont été trouvés en s1
			// sans interruption, donc s2 est présent dans s1 à partir de i
			if (j == s2len) 
				return ((char *)(s1 + i)); 
			// Retourne un pointeur vers le début de s2 dans s1 si trouvé
			// On aura s1 a partir de la position i, ce qui est egal a s2
			// (s1 + i) casté en char car char est attendue
		}
		i++;
	}
	return (0); // Retourne NULL si s2 n'est pas trouvé dans s1
}*/