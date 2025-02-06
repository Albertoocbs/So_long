/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:30:55 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/19 19:00:35 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	new = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (new);
}
/*
Concatène et alloue en mem deux chaînes de carac dans une seule nouvelle chaîne

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;//pointeur qui parcours la mem pour copier les carac de s1 s2
	char	*new;//pointeur pour conserver l'adresse de dèpart 

	Si l'un des parametres est NULL, la fonction renvoie NULL	
	if (!s1 || !s2)
		return (NULL);

	Alloue la memoire pour la nouvelle chaine avec taille s1 + s2 et + 1('\0')
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL); // Si lâllocation echoue, renvoi NULL

	new = str; 
	//Conserve l'adresse de départ dans new pour pouvoir la retourner à la fin

	while (*s1) // Copie chaque caractère de s1 dans str et incremente str
		*str++ = *s1++;
	while (*s2) // Copie s2 a la suite de s1 et incremente str
		*str++ = *s2++;
	*str = '\0';
	return (new); 
	Retourne le pointeur vers la nouvelle chaîne concaténée, 
	en utilisant l'adresse de départ
}*/