/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:53:32 by aoutumur          #+#    #+#             */
/*   Updated: 2025/01/14 10:22:24 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int		str;
	char	*num;

	str = 0;
	num = ft_itoa(n);
	if (!num)
		return (0);
	str = ft_print_str(num);
	free(num);
	return (str);
}
/* 
	Traite les conversions %d et %i.

	Cette fonction affiche un entier sur la sortie standard en le transformant
	d'abord en une chaîne de caractères avec ft_itoa qui represent l'entier.

	Retourne la taille de la chaîne affichée.

int	ft_print_nbr(int n)
{
	int		str;
	char	*num;

	str = 0;
	num = ft_itoa(n); // Convertit l'entier en chaîne de caractères.
	if (!num)
		return (0);
	str = ft_print_str(num); // Affiche la chaîne et stocke sa longueur dans str.
	free(num); // Libère la mémoire allouée par ft_itoa.
	return (str); // Retourne la taille de la chaîne affichée.
}*/
