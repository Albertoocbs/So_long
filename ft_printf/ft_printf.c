/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:18:17 by aoutumur          #+#    #+#             */
/*   Updated: 2025/01/14 10:19:36 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_formats(va_list args, const char format)
{
	int	str;

	str = 0;
	if (format == 'c')
		str += ft_print_char(va_arg(args, int));
	else if (format == 's')
		str += ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		str += ft_print_nbr(va_arg(args, int));
	else if (format == 'p')
		str += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		str += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		str += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		str += ft_print_percent();
	return (str);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/* 
Gére les formats spécifiques (%s, %d,etc),en appelant les fonctions 
correspondantes pour afficher les arguments dans la sortie standard

Cette fonction prend deux paramètres :
	- va_list args : pour accéder aux arguments de type variable
	- const char format : le caractère représentant le type de conversion 
	  (par exemple, 's', 'c', 'd', etc.)

int	ft_formats(va_list args, const char format)
{
	int	str;

	str = 0;

	Si le format est 'c', on affiche l'argument en utilisant ft_print_char
	if (format == 'c')
		str += ft_print_char(va_arg(args, int));

	Si le format est une chaine,on affiche la chaîne complète avec ft_print_str
	else if (format == 's')
		str += ft_print_str(va_arg(args, char *)); 
		// Récupère l'argument suivant de type char* dans la liste va_list,
	// puis le passe à ft_print_str pour afficher toute la chaîne de caractères
    //str sert à accumuler le nombre total de caractères affichés par ft_printf

		****Exemple:****
		str = 0; 
		str += ft_print_str("Bonjour");

		Que se passe-t-il ?
			ft_print_str("Bonjour") affiche "Bonjour" dans la sortie standard.
			La fonction retourne la valeur 7 (car "Bonjour" a 7 caractères).
		str est mis à jour comme suit :
			str = str + 7; // Donc, str = 7

		Si un autre appel suit :
			str += ft_print_str(" !"); // Affiche " !" et retourne 2
		Le total devient :
			str = 7 + 2; // str = 9


	Si le format est 'd' ou 'i' (entier), on affiche l'entier avec ft_print_nbr
	else if (format == 'd' || format == 'i')
		str += ft_print_nbr(va_arg(args, int));

	Si le format est 'p' (pointeur), on affiche l'adresse avec ft_print_ptr
	else if (format == 'p')
		str += ft_print_ptr(va_arg(args, unsigned long long));

	Si le format est 'u' (entier non signé), on utilise ft_print_unsigned
	else if (format == 'u')
		str += ft_print_unsigned(va_arg(args, unsigned int));

	Si le format est 'x' ou 'X' (hexadécimal), on utilise ft_print_hex
	else if (format == 'x' || format == 'X')
		str += ft_print_hex(va_arg(args, unsigned int), format);

	Si le format est '%', on affiche un pourcentage avec ft_print_percent
	else if (format == '%')
		str += ft_print_percent();
	
	return (str); 
	// Retourne finalement le nombre total de caractères affichés
	L'opérateur += est essentiel pour accumuler le résultat de plusieurs appels
}
Fonction principale, affiche le format demandé dans la sortie standard au fur
et a mesure de l'execution de la boucle while.

Retourne le nombre total de caractères affichés.

Cette fonction peut gérer un nombre d'arguments variables de types différents, 
grâce aux macros va_list, va_start, va_arg, et va_end.

int	ft_printf(const char *str, ...)
{
	int		i;    // Index pour parcourir str
	int		len;  // Compteur du nombre total de caractères affichés
	va_list	args; // Liste des arguments variables

	i = 0;
	len = 0;
	va_start(args, str); // Initialise les arguments

	// Boucle pour parcourir chaque caractère de str
	while (str[i])
	{
		// Si on rencontre '%', on gère le format de conversion
		if (str[i] == '%')
		{
			// Appelle ft_formats pour traiter le format et incrémente i
			len += ft_formats(args, str[i + 1]); str[% +'s'] contient le format
			i++; // 's' Sauté grâce à i++ après le traitement
		}
		else
			// Sinon, affiche le caractère actuel avec ft_print_char
			et incremente str pour passer a l'lement suivant.
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args); // Termine l'utilisation de la liste args
	return (len); // Retourne le nombre total de caractères affichés utile si
	on veut l'utilise rplus tard
}*/