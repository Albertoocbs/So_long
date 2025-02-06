/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:25:28 by aoutumur          #+#    #+#             */
/*   Updated: 2024/11/01 11:41:06 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;

	d = c;
	while ((*s) && (*s != d))
	{
		s++;
	}
	if (*s == d)
		return ((char *)s);
	return (NULL);
}
/*  
	Recherche dans une chaîne de caractères terminée par \0.
	Retourne pointeur (s) vers la 1er occurrence du caractère trouvé (c)
    ou NULL si le caractère n’est pas trouvé.

	- c = caractere a trouver dans la chaine
	- s = pointeur vers la chaine de caracteres ou effectuer la recherche

char	*ft_strchr(const char *s, int c)
{
	char	d;

	d = c;
	while ((*s) && (*s != d))
	{ 
	//tan qu'on pas arrivé a \0 et que occurrence de c et pas trouvée on avance
	s++;
	}
	//on verifie condition if si on est sorti boucle car trouvé occurrence c
	if (*s == d)
	{
		return ((char *)s); //retourne pointeur (s) vers l'occurrence
		// on cast s car le retour d'un char est attendue est pas un const char
		// sans les cast le compilateur emmetra avertissment
	}
	return (NULL); 
	// si on sort de la boucle en ayant atteint \0 sans trouver c,
	// on retourne NULL pour indiquer que c n'est pas dans la chaîne
*/