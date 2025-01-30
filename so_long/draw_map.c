/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:12:49 by aoutumur          #+#    #+#             */
/*   Updated: 2025/01/29 18:26:54 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/minilibx-linux/mlx.h"

void draw_map(t_data *data)
{
    int y = 0;
    while (y < data->rows)
    {
        int x = 0;
        while (x < data->cols)
        {
            int pos_x = x * TILE_SIZE;
            int pos_y = y * TILE_SIZE;

            if (data->map[y][x] == '1') // Mur
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall_img, pos_x, pos_y);
            else if (data->map[y][x] == '0') // Sol
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img, pos_x, pos_y);
            else if (data->map[y][x] == 'P') // Joueur
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img, pos_x, pos_y);
            else if (data->map[y][x] == 'C') // Collectible
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible_img, pos_x, pos_y);
            else if (data->map[y][x] == 'E') 
            {
                if (data->collected == data->total_collectibles)
                    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_img, x * TILE_SIZE, y * TILE_SIZE);
                else
                    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img, x * TILE_SIZE, y * TILE_SIZE);
            }
            x++;
        }
        y++;
    }
}
