/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:12:49 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/04 12:23:46 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/minilibx-linux/mlx.h"
#include "so_long.h"

void	put_tile_to_window(t_data *data, int x, int y, char tile)
{
	void	*img;

	if (tile == WALL)
		img = data->wall_img;
	else if (tile == FLOOR)
		img = data->floor_img;
	else if (tile == PLAYER)
		img = data->player_img;
	else if (tile == COLLECTIBLE)
		img = data->collectible_img;
	else if (tile == EXIT)
	{
		if (data->collected == data->total_collectibles)
			img = data->exit_img;
		else
			img = data->floor_img;
	}
	else
		return ;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x * TILE_SIZE, y
		* TILE_SIZE);
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			put_tile_to_window(data, x, y, data->map[y][x]);
			x++;
		}
		y++;
	}
}
