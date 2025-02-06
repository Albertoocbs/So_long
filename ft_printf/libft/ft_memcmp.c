/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:05:40 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/14 18:18:12 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
	Compare deux blocs de memoire de n octets pointées par s1 et s2 
	et retourne un entier negatif si s1 < s2 et positif si s1 > s2
	
	- s1 = pointeur vers le 1er bloc memoire
	- s2 = pointeur vers le 2eme bloc memoire
	- n = nombre octets(bytes) a comparer
	
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1; // variable pour caster s1
	unsigned char	*str2; // variable pour caster s2
	size_t			i; // variable index pour parcourir les elements des blocs

	str1 = (unsigned char *)s1;//cast car on veux eviter valeurs negatives
	str2 = (unsigned char *)s2;//cast car on veux eviter vn et comport innatend
	i = 0;
	while (i < n) 
	// Parcourt chaque octet des deux blocs de mem un par un jusqau n octets
	{
	//Si les octets de s1 et s2 diffèrent, retourne la différence entre eux
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0); 
	//Si les octets de s1 sont identiques à ceux de s2, la fonction retourne 0
}*/