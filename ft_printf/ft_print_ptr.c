/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:00:03 by aoutumur          #+#    #+#             */
/*   Updated: 2025/01/14 10:19:32 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	ft_ptr_len(unsigned long long num)
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

void	ft_putnbr_base(unsigned long long num)
{
	if (num >= 16)
	{
		ft_putnbr_base(num / 16);
		ft_putnbr_base(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	unsigned long long	num;
	int					len;

	num = (unsigned long long)ptr;
	if (num == 0)
		return (ft_putstr("0x0"));
	ft_putstr("0x");
	ft_putnbr_base(num);
	len = ft_ptr_len(num);
	return (len + 2);
}

/*
Cette fonction ecrit une chaine des caracteres passé en parametre
 sur la sortie standard

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i]) // Parcourt chaque caractère de la chaîne
	{
		write(1, &str[i], 1); // Affiche le caractère actuel
		i++;
	}
	return (i); // Retourne la longueur totale de la chaîne
}
****************										**********************
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
****************										*********************
Cette fonction affiche un entier non signé en base 16 (hexadécimal).
Utilise la récursivité pour afficher chaque chiffre

void	ft_putnbr_base(unsigned int num)
{
	if (num >= 16) // verifie si num >= 16
	{	
		Si c'est le cas recursive pour separer toutes les chiffres de num
		ft_putnbr_base(num / 16); 
		ft_putnbr_base(num % 16);
	}
	else //Sinon on affiche directement le chiffre en le convertissant en ASCII
	{	
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1); // Convertit les chiffres de 0 à 9 
		else
			ft_putchar_fd((num - 10 + 'a'), 1);//Converti les chiffres de A à F
	}
}
************************ 								**********************

Cette fonction affiche l'adresse mémoire d'un pointeur (format %p)

Elle affiche le préfixe "0x" pour indiquer un format hexadécimal,
	suivi de la représentation hexadécimale de l'adresse

int	ft_print_ptr(unsigned long long ptr)
{
	unsigned long long	num;
	int					len;

	num = (unsigned long long)ptr; // Convertit le pointeur en entier non signé
	if (num == 0)
		return (ft_putstr("0x0")); // si NULL affiche "0x0" directement
	ft_putstr("0x"); // Affiche le préfixe pour indiquer un format hexadécimal
	ft_putnbr_base(num); // Affiche la valeur hexadécimale de l'adresse
	len = ft_ptr_len(num); // Calcule la longueur de la partie hexadécimale
	return (len + 2); //Retourne la longueur totale: chiffres hexadécimaux + 0x
}*/