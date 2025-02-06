/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:34:36 by aoutumur          #+#    #+#             */
/*   Updated: 2024/11/05 15:53:18 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg = neg * -1;
		}
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}
/* //transform une chaine qui represente un entier en valeur numerique int
int	ft_atoi(const char *str) 
{
	int	neg; // variable pour traiter les cas negatif 
	int	i; //variable qui sert comme index pour parcourir la chaine
	int	num; // variable qui sert a stocker le resultat de la chaine

	i = 0; 
	neg = 1; // 1 pour pouvoir faire la transformer quand neg * -1
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++; // au cas ou y a space, tab, etc est on passe au prochain carac
	if (str[i] == '-' || str[i] == '+')
	{ //au cas ou cêst - en passe a positif est si + en passe au prochain carac
		if (str[i] == '-')
		{
			neg = neg * -1;
		}
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{ // si le carac est num on stocke dans num sa valeur, transform avec -48
		num = num * 10 + (str[i] - 48); num*10 laisse place x le prochain carac
		i++;
	}
	return (num * neg); retour valeur chaine transf en int 
}*/