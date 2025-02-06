/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:50:31 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/06 13:02:35 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/minilibx-linux/mlx.h"
#include "so_long.h"

void	flood_fill(char **map, int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x >= data->cols || y >= data->rows)
		return ;
	if (map[y][x] == WALL || map[y][x] == 'V')
		return ;
	if (map[y][x] == COLLECTIBLE)
		data->acc_collectibles++;
	if (map[y][x] == EXIT)
		data->exit_found = 1;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}

char	**copy_map(t_data *data)
{
	int		y;
	char	**map_copy;

	map_copy = malloc(sizeof(char *) * data->rows);
	if (!map_copy)
	{
		perror("Erreur d'allocation mémoire");
		exit(1);
	}
	y = 0;
	while (y < data->rows)
	{
		map_copy[y] = malloc(sizeof(char) * (data->cols + 1));
		if (!map_copy[y])
		{
			perror("Erreur d'allocation mémoire");
			exit(1);
		}
		strncpy(map_copy[y], data->map[y], data->cols);
		map_copy[y][data->cols] = '\0';
		y++;
	}
	return (map_copy);
}

void	check_valid_path(t_data *data)
{
	char	**map_copy;
	int		y;

	if (data->player_x < 0 || data->player_x >= data->cols || data->player_y < 0
		|| data->player_y >= data->rows)
	{
		ft_printf("Erreur position du joueur\n");
		exit(1);
	}
	data->acc_collectibles = 0;
	data->exit_found = 0;
	map_copy = copy_map(data);
	flood_fill(map_copy, data->player_x, data->player_y, data);
	y = 0;
	while (y < data->rows)
		free(map_copy[y++]);
	free(map_copy);
	if (data->acc_collectibles != data->total_collectibles || !data->exit_found)
	{
		if (data->acc_collectibles != data->total_collectibles)
			ft_printf("Erreur: Tous les collectibles ne sont pas accessibles\n");
		if (!data->exit_found)
			ft_printf("Erreur: La sortie n'est pas accessible\n");
		exit(1);
	}
}
