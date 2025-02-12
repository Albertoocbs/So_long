/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:16:07 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/12 13:08:08 by aoutumur         ###   ########.fr       */
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

void	destroy_and_exit(t_data *data)
{
	if (data->wall_img)
		mlx_destroy_image(data->mlx_ptr, data->wall_img);
	if (data->player_img)
		mlx_destroy_image(data->mlx_ptr, data->player_img);
	if (data->collectible_img)
		mlx_destroy_image(data->mlx_ptr, data->collectible_img);
	if (data->floor_img)
		mlx_destroy_image(data->mlx_ptr, data->floor_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx_ptr, data->exit_img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	free_map(data->map, data->rows);
	exit(0);
}

int	close_window(t_data *data)
{
	ft_printf("Fenetre fermé avec button x\n");
	destroy_and_exit(data);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		ft_printf("Fenetre fermé avec ESC\n");
		destroy_and_exit(data);
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
	mlx_key_hook(data.win_ptr, handle_keypress, &data); -> Gére les touches */
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file.ber>\n", argv[0]);
		return (1);
	}
	init_game(&data, argv[1]);
	load_sprites(&data);
	draw_map(&data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_hook(data.win_ptr, CLOSE_EVENT, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
	destroy_and_exit(&data);
	return (0);
}
/*Toutes les ressources MiniLibX et mém dynamique sont correctement libérées
Les blocs 'still reachable' sont dus aux allocs internes
de X11/MiniLibX sous Linux, ce qui est normal et hors de notre contrôle.*/
