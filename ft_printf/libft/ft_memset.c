/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:38:29 by aoutumur          #+#    #+#             */
/*   Updated: 2024/11/05 16:12:44 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	str = s;
	while (len != 0)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (s);
}
/*
Rempli une zone de memoire avec une valeur specifique (c)
Normalement pour initialiser ou reinitialiser la memoire(tableaux,structures..)
On utilise ft_memset pour remplir une zone de memoire avec des zeros par exempl

- s = pointeur vers la zone de memoire a remplir
- c = valeur a remplir dans la zone de memoire
- len = nombre d'octets a remplir

Retourne le pointeur vers la zone de memoire qui a été remplie(s)

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;//declare pointeur str pour manipuler la memoire
	//et assurer des valeurs non signées

	str = s; //assigne s a str, avec un cast implicite vers unsigned char *
	while (len != 0)//tant quil reste des octets a remplir la boucle s'execute
	{
		*str = (unsigned char)c; //assigne la valeur de c a l'emplacement mem
		// pointéee par str ce quie la meme chose que s
		str++;//on passe a l'octet suivant
		len--;//on décrémente len, et on sort de la boucle une fois len à zéro
	}
	return (s);// retourne un pointeur vers la zone de memoire remplie (s)
}*/
