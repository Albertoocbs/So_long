/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:15:17 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/06 09:50:24 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/minilibx-linux/mlx.h"
#include "so_long.h"

void	move_player(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] == WALL)
		return ;
	if (data->map[new_y][new_x] == COLLECTIBLE)
	{
		data->collected++;
		data->map[new_y][new_x] = FLOOR;
		draw_map(data);
	}
	if (data->map[new_y][new_x] == EXIT
		&& data->collected == data->total_collectibles)
	{
		ft_printf("Bravo ! Vous avez gagné !\n");
		exit(0);
	}
	data->map[data->player_y][data->player_x] = FLOOR;
	data->map[new_y][new_x] = PLAYER;
	data->player_x = new_x;
	data->player_y = new_y;
	data->moves++;
	ft_printf("Mouvement: #%d\n", data->moves);
	draw_map(data);
}

/*
void	move_player(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] == WALL) //Mur, ne pas bouger
	if (data->map[new_y][new_x] == COLLECTIBLE) //Collectible ramassé
	if (data->map[new_y][new_x] == EXIT //
		&& data->collected == data->total_collectibles)
	{
		ft_printf("Bravo ! Vous avez gagné !\n");
		exit(0);
	}
	//Déplacer le joueur
	data->map[data->player_y][data->player_x] = FLOOR; //Ancienne position
	data->map[new_y][new_x] = PLAYER; // Nouvelle position
	data->player_x = new_x;
	data->player_y = new_y;
	data->moves++; // incrementer moves pour le compteur
	ft_printf("Mouvement #%d: (%d, %d)\n", data->moves, data->player_x,
		data->player_y);
	draw_map(data); // dessiner la map
}*/
