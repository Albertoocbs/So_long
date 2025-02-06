/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:26:12 by aoutumur          #+#    #+#             */
/*   Updated: 2025/01/14 10:19:37 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* FT_PRINTF_H est une macro de protection pour éviter les inclusions multiples 
   du fichier d'en-tête ft_printf.h
   La directive ifndef/define informe le préprocesseur de créer les définitions 
   seulement si elles n'existent pas déjà.
*/
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>       
# include <stdio.h> 
# include <stdlib.h>  
# include <unistd.h>

/*---------------- Fonction principale de printf --------------*/
int		ft_printf(const char *str, ...);

/*--------- Fonctions de Formats pour les conversions --------*/
int		ft_formats(va_list args, const char format);

/*--------------- Fonctions de Conversion -----------------*/
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_nbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_percent(void);

/*--------------- Fonctions Auxiliaires -----------------*/
char	*ft_uitoa(unsigned int n);
void	ft_putnbr_hex(unsigned int num, const char format);
int		ft_putstr(const char *str);
void	ft_putnbr_base(unsigned long long num);

#endif
