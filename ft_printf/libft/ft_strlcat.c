/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:46:16 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/22 17:48:26 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst && size == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] && (dst_len + i < size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
Concatene une chaine src aprés dst en assurant que dst ne depasse pas size

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len; 
	size_t	src_len;
	size_t	i;

	// Vérification des cas spéciaux : si dst est NULL et size est 0
	// On retourne la longueur de src, car on ne peut pas concatener dans ce cas
	if (!dst && size == 0)
		return (ft_strlen(src));

	// On obtient la longueur de dst et src
    dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);

	// Si la longueur de dst depasse ou et egal a size
	// on retourne src + size, car on peut pas faire la concatenation complete
	if (size <= dst_len)
		return (src_len + size);
	
	// On commence à copier src à la suite de dst.
	i = 0;
	while (src[i] && (dst_len + i < size - 1))//On laisse de la place pour '\0'
	{
		dst[dst_len + i] = src[i]; //Fait la copie aprés dst_len + i dans dst
		i++;
	}
	dst[dst_len + i] = '\0';  // Ajoute le caractère nul final

	return (dst_len + src_len);
	// Retourne la longueur totale teorique de dst_len + src_len
	// Si size est supérieur ou égal à ce retour, 
			dst peut accueillir toute la concaténation.
	// Si size est inférieur à ce retour, dst n'aura pas assez de place 
			pour src en entier, et la concaténation sera donc tronquée
}*/