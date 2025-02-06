/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:00:00 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/19 19:09:09 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, (char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
	Applique une fonction f a chaque caractere de la chaine s
	et stocke le résultat dans une nouvelle chaine allouée en mémoire

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str; 

	if (!s || !f) // Si s ou f sont NULL la fonction quitte inmediatement
		return (NULL);
	len = ft_strlen(s); // Calcule la longueur totale de s

	// Alloue assez de memoire pour stocker la nouvelle chaine str
	str = (char *)malloc(len + 1); 
	if (!str)
		return (NULL); // Si l'allocation echoue la fonction retourne NULL
	i = 0;
	while (s[i]) // Parcourt chauqe caractere de s jusqua la valeur nul
	{
		str[i] = f(i, (char)s[i]); //Aplique la fonction f 
		// a chaque caractere de s et copie le resultat dans str
		i++;
	}
	str[i] = '\0'; // Termine str avec la valeur nul
	return (str); // Retourne le pointeur vers la nouvelle chaine alloué
}*/