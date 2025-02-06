/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:08:53 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/19 18:13:45 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
	Applique une fonction (f) a chaque caractere de la chaine pointé par (s)
	La fonction prends en parametre un index (unsigned int) 
	et un pointeur vers un caractère (char *) 
	en permettant de manipuler chaque caractère de s

	s : Pointeur vers la chaîne de caractères sur laquelle on veut appliquer f
	f : Pointeur vers fonction 

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f) // Si s ou f est NULL, la fonction quitte immédiatement
		return ;
	i = 0;
	while (s[i]) // incremente i jusqu’à la fin de la chaîne (\0) 
	{
    	f(i, &s[i]); // Et on applique la fonction f a chaque caractere de s
    	i++;
	}
}*/