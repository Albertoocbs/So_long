/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:06:58 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/13 09:32:33 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/minilibx-linux/mlx.h"
#include "so_long.h"

void	free_and_exit(t_data *data)
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
	if (data->map)
		free_map(data->map, data->rows);
	if (data->mlx_ptr)
	{
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(1);
}
