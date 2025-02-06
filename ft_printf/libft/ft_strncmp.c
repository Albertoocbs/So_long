/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:58:35 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/13 11:15:08 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
	Compare deux chaines de caracteres s1 et s2 jusqua n caracteres
	et retourne la difference des qune est trouvée

	Si s1 < s2 le nombre retourné sera negatif
	Si s1 > s2 le nombre retourné sera positif
	Si les chaines sont identiques jusqua n caracteres, la fonction retourne 0

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0) // Si n == 0 la fonction quitte inmediatement
		return (0);

	// Parcourt chaque element des deux chaines au meme temps jusqua n caracter
	while (i < n && s1[i] && s2[i]) 
		if (if ((unsigned char)s1[i] != (unsigned char)s2[i]) 
		// Retourne la la diff dès quon trouve une
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0); // Retourne 0 aucune difference trouvé jusqua n caracteres
}*/