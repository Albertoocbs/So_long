/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:00:17 by aoutumur          #+#    #+#             */
/*   Updated: 2025/01/14 10:19:35 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char		*str;
	long int	len;

	len = ft_num_len(n);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	num = ft_uitoa(n);
	if (!num)
		return (0);
	len = ft_print_str(num);
	free(num);
	return (len);
}

/*
Cette fonction locale ft_num_len  calcule la longueur de l'entier non signée

int	ft_num_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1); // si l'entier est 0 retourne 1 (longueur sera toujours 1)
	while (n != 0) // parcours chaque chiffre jsuqau n cest egal a 0
	{
		n = n / 10; // enleve une chiffre de l'entier a chaque fois
		len++; // incremente (compte) 1 pour chaque chiffre
	}
	return (len); // Renvoie longueur totale de l'entier
}
Cette fonction transforme un entier non signé en un chaine de caracteres 
Retourne la chaine de caracteres qui represente l'entier transformée

char	*ft_uitoa(unsigned int n)
{
	char		*str;
	long int	len;

	len = ft_num_len(n); // assigne a len la longueur de l'entier
	str = ft_calloc((len + 1), sizeof(char)); // alloue l'espace pour la chaine
	if (!str)
		return (NULL); // verifie si l'allocation echou et renvoie NULL
	str[len] = '\0'; // rajoute caractere nul a la fin de str
	while (len--) // parcour str depuis la fin jusqau len 0
	{
		str[len] = '0' + (n % 10); // stocke valeur de l'entier transformé
		n = n / 10; // sert comme index pour eliminer une chiffre a chaque fois
	}
	return (str); // retourne la chaine (str) 
}
Cette fonction prend comme parametre un entier non sigé et l'affiche sur la 
sortie standard

Retourne la taille de l'entier affiché.

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	num = ft_uitoa(n);//fait la transformation de l'entier en appelant ft_uitoa
	if (!num)
		return (0); // verification de l'allocation
	len = ft_print_str(num); // appel ft_print_str pour afficher la chaine 
							qui represnete l'entier dans la sortie standard et
							stocke la valeur de la longueur dans len
	free(num); // libere la memoire de num
	return (len); // Retourne la taille (len) de la chaine affiché
}*/