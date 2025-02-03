/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:02:01 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/03 12:55:24 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/minilibx-linux/mlx.h"

void    load_sprites(t_data *data)
{
   int  width;
   int  height;

   data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/wall.xpm", &width, &height);
   data->player_img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/player.xpm", &width, &height);
   data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/collectible.xpm", &width, &height);
   data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/floor.xpm", &width, &height);
   data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/exit.xpm", &width, &height);

   if (!data->exit_img || !data->floor_img || !data->player_img || !data->collectible_img || !data->wall_img)
   {
     printf("Error loading images\n");
     exit(1);
   }
}