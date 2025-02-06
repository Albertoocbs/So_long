/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:50:28 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/19 17:53:12 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	num;

	num = n;
	len = n_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[len--] = '0' + (num % 10);
		num = num / 10;
	}
	return (str);
}
/*
static int	n_len(int n)
{
	int	len;

	// la condition laisse place pour le signe - ou le 0 (len = 1) si c le cas
	len = 0;
	if (n <= 0)
		len++;
	//la boucle calcul combien de chiffres a l'entier jusquarriver a 0
	//sans compter le signe - ou le 0 (calculé dans le if) dès len = 1
	//le num d'iteracions jusqua 0 c'est la taille de len quon renvoi ex: len=5
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
	//ft_itoa va convertir le numero en chaine
char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long int    num;
	
	// pour eviter de valeurs residuelles qui peuvent causer erreurs moulinette
	//et on gere le cas ou calloc echoue renvoyant null
	num = n;
	len = n_len(n);
	//on alloue la mem avec ft_calloc avec len (5) + 1 ('\0')
	//on utilise ft_calloc pour initialiser mem avant d'allouer
	str = ft_calloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0'; // str[6] = '\0'; et decremente apres
	if (num == 0)
		str[0] = '0'; // si n=0 on assigne le caracter 0 a la 1er pos dla chaine
	if (num < 0)
	{
		// si n negative on assigne le caracter - a la 1er pos dla chaine
		str[0] = '-';
		num = -num;//convertir num en postif pour le traiter dans boucle apres
	}
	while (num > 0) // rempli la chaine avec les chiffres de droite a gauche
	{
		// str[5]et en decremente 1 a la fois et on converti en caractere
		str[len--] = '0' + (n % 10);
		num = num / 10;
		// 1234/10=123 123/10=12 12/10=1 1/10=0 on sort dla boucle et renvoi str
	}
	return (str);
}*/