/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:04:14 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/22 17:18:34 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*

Copie chaine de caracteres(src) sur une nouvelle (res) 
avec une nouvelle allocation de memoire

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	i;

	i = 0;
	while (src[i]) //on fait un strlen pour obtenir la taille de src
	{
		i++;
	}
	res = (char *)malloc(i + 1); //on alloue la mem necessaire pour la copie
	if (!res)
		return (NULL);// si l'allocation echou en renvoi NULL
	i = 0;
	while (src[i]) // tant quon arrive pas a la valeur nul
	{
		res[i] = src[i]; //on fait la copie de src sur res
		i++;
	}
	res[i] = '\0'; // on fini la chaine avec la valeur nul
	return (res); // onm renvoi pointeur vers la nouvelle chaine
}*/