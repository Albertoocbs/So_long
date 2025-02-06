/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:18:15 by aoutumur          #+#    #+#             */
/*   Updated: 2024/10/19 18:22:11 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/* Ecrit un caractere dans un fichier a l'aide d'un descripteur de fichier
Un fd c'est un numero unique(descripteur), un identifiant temporaire attribué 
par le systeme pour permettre aux programmes d'acceder et d'interagir avec */