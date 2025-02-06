/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:35:00 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/22 17:03:10 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	if (src == dest)
		return (dest);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (src_ptr < dest_ptr && src_ptr + len > dest_ptr)
		while (len--)
			dest_ptr[len] = src_ptr[len];
	else
		return (ft_memcpy(dest, src, len));
	return (dest);
}
/*
	Copie des blocs de mem d'une source vers une zone de mem destination meme
	si les deux ces chevauchent, contrairement a ft_memcpy qui fait la meme
	chose mais quand les blocs de mem ne se chevauche pas.

	- dest = pointeur vers la destination (ou on copie les octets)
	- src = pointeur vers la source (octets a copier)
	- len = nombre d'octets a copier

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_ptr;//declare pointeur pour puvoir caster apres
	const unsigned char	*src_ptr;

	if (src == dest) //si sont identiques return dest
		return (dest);
	//on cast pour garantir que les valeurs seront manipulées correctement 
	//comme des octets non signés
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	// Si src est avant dest et que les zones se chevauchent
	if (src_ptr < dest_ptr && src_ptr + len > dest_ptr)
		while (len--)// // Copie de fin à début pour éviter l'écrasement
			//on commence par le dernier octet len - 1 
			//et ensuite on decremente  est on copie
			dest_ptr[len] = src_ptr[len];
			//copie chaque octet depuis src vers dest en partant de la fin
	else
		return (ft_memcpy(dest, src_ptr, len); 
		// si il y a pas de chevauchement on utilise ft_memcpy pour optimiser
		// pour faire la copiedu debut a la fin
	return (dest); //retourne pointeur vers dest ou on a copié les blocs de mem
}*/