/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:51:54 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/13 10:28:40 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
	Copie n nombre d'octets de la mem pointé par src vers celle de dest 
	elles ne doivent pas se chevaucher 

    - dest = pointeur vers la destination (copie des octets)
    - src = pointeur vers la source (octets a copier)
	- n = nombre d'octets a copier

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i; 
	//variable qui sert comme index pour parcourir chaque element du bloc mem

	i = 0;
	if (!src && !dest)// Si y a rien dans dest et src on retourne direct 0
	{
		return (0);
	}
	while (i < n)//boucle parcours chaque element dans src et copie dans dest
	{
	    //cast en unsigned char car on traite avec bloc de mem 
		//et on veux eviter valeurs signés et des comportements innatendues 
		//et comme valeur de char est 1 octets on peux parcourir chaque element
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);//retour dest après avoir copie les n octets de src dans dest
}*/