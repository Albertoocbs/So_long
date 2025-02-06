/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:37:33 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/19 18:38:14 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}
/*
Ecrit un entier n dans un fichier a l'aide d'un descripteur de fichier

void	ft_putnbr_fd(int n, int fd)
{ 
Si le'entier est la valeur min d'un entier on affiche -2 et on utilise 
Recursive pour afficher le reste des chiffres
	if (n == -2147483648)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483648, fd);
			return ;
		}
	if (n < 0)
	{
	Si l'entier est negatif on affiche - et on le transform en positif
		ft_putchar_fd('-', fd);
		n = -n;
	}
	Utilise la recursion pour separer les chiffres du nombre entier avec putnbr
	Ensuite les affiche un par un, retour en arriere dans la pile
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}*/