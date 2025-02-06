/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:52:29 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/15 18:26:39 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == ch)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}
/* //Retourne pointeur (s) vers la 1er occurrence du caractère trouvé (c)
	//ou NULL si le caractère n’est pas trouvé.
	//cherche 1er occ de c dans le n 1er octets dans zone mem pointé par s 
	//n = (nombre octets a examiner dans la mem)
void	*ft_memchr(const void *s, int c, size_t n) 
{
	unsigned char	*str; //variable pour pouvoir caster s
	unsigned char	ch; //variable pour pouvoir caster c
	size_t			i; //variable index pour parcourir le tableau ou bloc mem 

	i = 0;
	str = (unsigned char *)s;on cast s en unsigned pour eviter valeurs negatifs
	ch = (unsigned char)c; on cast c en unsigned car on travaille avec memoire
	while (i < n) // parcour bloc mem pointé par s jusqua n octets 
	{
		if (str[i] == ch)//si val act str[i] egal à ch(c),carac cherché trouvée
		{ 
			return (str + i);
		}//retourne pointeur vers emplcement 1er occurr (i) de ch(c) dans str(s)
		i++;
	}
	return (NULL); retourne NULL si le caractère n’est pas trouvé.
}*/