/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:21:18 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/15 17:57:49 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*res;
	size_t	i;
	size_t	total_size;

	total_size = nitems * size;
	res = (char *)malloc(total_size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
/*  // Alloue un bloc de mémoire en initialisant tous ces octets à la valeur 0
	// combine malloc et bzero
	// si on a besoin d'allour et initialiser en meme temps

void	*ft_calloc(size_t nitems, size_t size)
{ //prend en param nitems=nombre d'elements x lequels la mem doit etre alloue
    			// et size=taille en octets de chaque element

	char	*res;//variable x allouer la mem est stocker resultat de l'init a 0
	size_t	i; //variable quie sert comme index pour parcourir res
	size_t	total_size; // variable qui stock la taille total a allouer

	total_size = nitems * size; //en stock la taille total a allouer
	res = (char *)malloc(total_size); //en alloue la mem necessaire avec malloc
	//alloue un bloc de mem de taille total_size octets
	if (!res)
		return (NULL); // si l'allocation echou retourn NULL
	i = 0;
	while (i < total_size)
	{
		res[i] = 0;// init chaque octet du bloc de mémoire res à la valeur 0 
		i++;
	}
	return (res); return pointeur vers zone de memoire alloué et initialisé

}*/