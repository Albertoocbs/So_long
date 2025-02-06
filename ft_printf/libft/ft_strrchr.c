/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:28:13 by aoutumur          #+#    #+#             */
/*   Updated: 2024/11/01 11:41:14 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	d;

	len = 0;
	d = c;
	while (s[len])
		len++;
	while (len >= 0)
	{
		if (s[len] == d)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
/*
	Cherche la derniere occurence de c dans la chaine de caractère s

	s = Chaine de caractère ou effectuer la recherche
	c = Caractère a trouver dans la chaine

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len]) // Calcule la longueur totale de s
		len++;

	// Parcourt chaque caractère de s en sens inverse, de la fin vers le début
	while (len >= 0)
	{
		if (s[len] == c) // Si on trouve occurence de c dans s
			return ((char *)&s[len]); 
		// Retourne un pointeur vers l'index de s ou on a trouvé l'occurrence
		// char est attendu en retour, donc on cast s[len] en char 
		len--; //Decremente len a chaque iteration pour avancer vers debut de s
	}
	return (NULL); 
	// Retourne NULL si aucune ocurrence de c n'a ete trouve dans s

}*/