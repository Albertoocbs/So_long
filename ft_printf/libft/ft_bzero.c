/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:44:56 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/12 13:18:27 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
/*  // pour initialiser tableaux avant leur 1er utillisation ou
	// reinitialiser zones de mem pour eviter des donnees residuelles
	// si la memoire a deja ete alloué avant et on veux seulement la remtre a 0
	// n = nombre octets(bytes) a mettre a zero
	// s = pointeur vers le debut de la zone d'octets a remplir 
void	ft_bzero(void *s, size_t n) 
{ // rempli des zeros la zone de memoire pointe par s. 
	i = 0;
	while (i < n)//parcours chaque position dans s[] jusqua arriver a val. de n
	{ // Initialize chaque octet du bloc de mem pointe par s a 0 un par un
		((char *)s)[i] = 0; //cast en char car char a un taille de 1 octet 
		i++;
	}
}*/