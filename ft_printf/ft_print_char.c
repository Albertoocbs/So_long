/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:44:48 by aoutumur          #+#    #+#             */
/*   Updated: 2025/01/14 10:21:33 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}
/* 
Cette fonction affiche un caracter dans la sortie standard et retourne 1.

Retourne -1 si il y a une erreur.
*/