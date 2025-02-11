/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:50:26 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/11 14:04:44 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/minilibx-linux/mlx.h"
#include "so_long.h"

/**
 * Charge la carte et vérifie sa validité.
 */
void	load_map(t_data *data, char *map_file)
{
	data->map = read_map(map_file, &data->rows, &data->cols);
	if (!data->map)
	{
		ft_printf("Erreur de chargement de la carte: %s\n", map_file);
		destroy_and_exit(data);
		exit(1);
	}
	validate_map(data);
}

/**
 * Trouve la position initiale du joueur 'P' et compte les collectibles 'C'.
 */
void	find_player_and_collectibles(t_data *data)
{
	int		y;
	int		x;
	char	cell;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			cell = data->map[y][x];
			if (cell == PLAYER)
			{
				data->player_x = x;
				data->player_y = y;
			}
			else if (cell == COLLECTIBLE)
				data->total_collectibles++;
			x++;
		}
		y++;
	}
}

/**
 * Initialise MiniLibX et crée la fenêtre.
 */
void	init_minilibx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printf("Erreur: MiniLibX n'a pas pu être initialisé.\n");
		exit(1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->cols * TILE_SIZE,
			data->rows * TILE_SIZE, "so_long");
	if (!data->win_ptr)
	{
		ft_printf("Erreur: Impossible de créer la fenêtre MiniLibX.\n");
		exit(1);
	}
}

/**
 * Fonction principale d'initialisation du jeu.
 */
void	init_game(t_data *data, char *map_file)
{
	data->rows = 0;
	data->cols = 0;
	data->collected = 0;
	data->total_collectibles = 0;
	data->moves = 0;
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	load_map(data, map_file);
	find_player_and_collectibles(data);
	check_valid_path(data);
	init_minilibx(data);
}
