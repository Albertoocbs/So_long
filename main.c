/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:16:07 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/04 12:23:41 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/minilibx-linux/mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	free_map(char **map, int rows)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_map(data->map, data->rows);
	ft_printf("Vous avez fermé la fenêtre avec le bouton X\n");
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free_map(data->map, data->rows);
		ft_printf("Vous avez ferme la fenetre avec ESC\n");
		exit(0);
	}
	if (keycode == W_KEY)
		move_player(data, data->player_x, data->player_y - 1);
	else if (keycode == S_KEY)
		move_player(data, data->player_x, data->player_y + 1);
	else if (keycode == A_KEY)
		move_player(data, data->player_x - 1, data->player_y);
	else if (keycode == D_KEY)
		move_player(data, data->player_x + 1, data->player_y);
	else if (keycode == UP_KEY)
		move_player(data, data->player_x, data->player_y - 1);
	else if (keycode == DOWN_KEY)
		move_player(data, data->player_x, data->player_y + 1);
	else if (keycode == LEFT_KEY)
		move_player(data, data->player_x - 1, data->player_y);
	else if (keycode == RIGHT_KEY)
		move_player(data, data->player_x + 1, data->player_y);
	draw_map(data);
	return (0);
}

/*if (argc != 2) Vérifie qu'un fichier de carte est passé en argument
while (y < data.rows) Trouve la position initiale de 'P' + num de 'C'
	load_sprites(&data);  -> Charge les images
	draw_map(&data);      -> Affiche la carte
	mlx_key_hook(data.win_ptr, handle_keypress, &data); -> Gére les touches*/
int	main(int argc, char **argv)
{
	t_data	data;
	int		y;
	int		x;

	if (argc != 2)
	{
		ft_printf("Aucun paramatre. Usage: %s <map_file.ber>\n", argv[0]);
		return (1);
	}
	data.rows = 0;
	data.cols = 0;
	data.collected = 0;
	data.total_collectibles = 0;
	data.moves = 0;
	data.map = read_map(argv[1], &data.rows, &data.cols);
	if (!data.map)
	{
		ft_printf("Error loading map: %s\n", argv[1]);
		return (1);
	}
	validate_map(&data);
	y = 0;
	while (y < data.rows)
	{
		x = 0;
		while (x < data.cols)
		{
			if (data.map[y][x] == PLAYER)
			{
				data.player_x = x;
				data.player_y = y;
			}
			else if (data.map[y][x] == COLLECTIBLE)
				data.total_collectibles++;
			x++;
		}
		y++;
	}
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.cols * TILE_SIZE, data.rows
			* TILE_SIZE, "so_long");
	load_sprites(&data);
	draw_map(&data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_hook(data.win_ptr, CLOSE_EVENT, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
	free_map(data.map, data.rows);
	return (0);
}
