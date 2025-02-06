/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:59:45 by aoutumur          #+#    #+#             */
/*   Updated: 2025/01/14 10:22:23 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned int num)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

void	ft_putnbr_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_putnbr_hex(num / 16, format);
		ft_putnbr_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd(num - 10 + 'a', 1);
			if (format == 'X')
				ft_putchar_fd(num - 10 + 'A', 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_putnbr_hex(num, format);
	return (ft_ptr_len(num));
}

/*
Cette fonction calcule la longueur d'un entier non signé exprimé en base 16 hex

Retourne la longueur (len) en nombre de chiffres nécessaires pour représenter
 l'entier en base 16.

int	ft_ptr_len(unsigned int num)
{
	int	len;

	if (num == 0) // si l'entier est 0 la longueur est toujours 1.
		return (1);
	len = 0;
	while (num != 0) // Boucle pour compter le nombre de chiffres nécessaires.
	{
		num = num / 16; // Divise l'entier par 16 pour réduire sa taille
		len++;
	}
	return (len); // Retourne la longueur totale en chiffres hexadécimaux.
}
*********************                                 ************************

Cette fonction affiche un entier non signé de base 16 hexadecimale .
Utilise la recursivité pour afficher chaque chiffre.

Avec Le format d'affichage ('x' pour minuscule, 'X' pour majuscule)

void	ft_putnbr_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_putnbr_hex(num / 16, format);
		ft_putnbr_hex(num % 16, format);
	}
	else //Sinon on affiche directement le chiffre en le convertissant en ASCII
	{
		if (num <= 9) 
			ft_putchar_fd((num + '0'), 1); // Convertit les chiffres de 0 à 9 
		else
		{
			if (format == 'x') //Converti les chiffres de a à a
				ft_putchar_fd(num - 10 + 'a', 1);
			if (format == 'X') //Converti les chiffres de A à F
				ft_putchar_fd(num - 10 + 'A', 1);
		}
	}
}
*********************** 								***********************

Cette fonction affiche le chifffre non signé de base 16 hexa en appellant 
ft_putnbr_hex précédé du préfixe correspondant
Avec le format d'affichage ('x' pour minuscule, 'X' pour majuscule)

Retourne le nombre total de caractères affichés

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));//Si le nombre est 0, affiche directement '0'
	else
		ft_putnbr_hex(num, format); // Affiche l'entier en base 16
	return (ft_ptr_len(num)); // Retourne la longueur du nombre affiché
}*/