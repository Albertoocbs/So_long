/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:49:22 by aoutumur          #+#    #+#             */
/*   Updated: 2025/01/14 10:19:27 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	return (ft_print_char('%'));
}

/*
Cette fonction affiche le caractere % dans la sortie standard on appelant la
fonction ft_print_char pour afficher le caractère.
*/