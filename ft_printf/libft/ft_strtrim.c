/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:30:06 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/22 17:22:03 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (is_set(s1[start], set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (is_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
/*
Fonction local qui cherche la premiere occurrence de c dans set

static int	is_set(char c, char const *set)
{
	while (*set) // Parcourt chaque caractere de set
	{
		if (*set == c) // Verifie si l’un d'entre eux est egal à c
			return (1); 
			// Si une correspondance est trouvée, 
			// la fonction retourne 1, indiquant que c est présent dans set
		set++;
	}
	return (0); // Si c n'est pas dans set retourne 0
}

//crée une nouvelle chaîne allouée dynamiquement en supprimant les caractères
// présents dans set au début et à la fin de s1

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	// si s1(la chaine source) est vide(NULL) on retourne une chaine vide
	if (!s1) 
		return (ft_strdup(""));

	// Si set est NULL, cela signifie qu'il n'y a pas de caractères à supprimer
	// La fonction retourne donc une copie complète de s1 avec ft_strdup(s1)
	if (!set)
		return (ft_strdup(s1));

	start = 0; // Index debut chaine
	end = ft_strlen(s1); // Calcule longueur de s1, index fin chaine

	// is_set verifie si le caractère actuel (s1[start]) est présent dans set
	// Tant que s1[start] est dans set, start est incrémenté du debut a la fin
	// La boucle s’arrête dès qu’un caractère de s1[start] n’est pas dans set
	while (is_set(s1[start], set))
		start++;

    // Si la chaine est vide (start == end), on retourne une chaine vide
	if (start == end)
		return (ft_strdup(""));

    // is_set verifie si le caractère actuel (s1[end - 1]) est présent dans set
	// Tant que s1[end - 1] est dans set, end est décrémenté de la fin au debut
    // La boucle s’arrête dès qu’un caractère de s1[end - 1] n’est pas dans set
	while (is_set(s1[end - 1], set))
		end--;

    // ft_substr crée une nouvelle chaine de caractères découpée de s1
	// à partir de l’indice start (exclu) jusqu’au début de l’indice end (exclu)
    // La fonction retourne un pointeur vers la nouvelle chaine créée alloué 
	return (ft_substr(s1, start, end - start)); 
}*/