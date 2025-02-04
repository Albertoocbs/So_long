/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:23:53 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/04 13:45:39 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/minilibx-linux/mlx.h"
#include "so_long.h"

void	check_walls(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->cols)
	{
		if (data->map[0][x] != WALL || data->map[data->rows - 1][x] != WALL)
		{
			ft_printf("Erreur: La carte n'est pas entourée de murs !\n");
			exit(1);
		}
		x++;
	}
	y = 0;
	while (y < data->rows)
	{
		if (data->map[y][0] != WALL || data->map[y][data->cols - 1] != WALL)
		{
			ft_printf("Erreur: La carte n'est pas entourée de murs !\n");
			exit(1);
		}
		y++;
	}
}

void	count_elements(t_data *data, int *player_count, int *exit_count,
		int *collectible_count)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			if (data->map[y][x] == PLAYER)
				(*player_count)++;
			else if (data->map[y][x] == EXIT)
				(*exit_count)++;
			else if (data->map[y][x] == COLLECTIBLE)
				(*collectible_count)++;
			x++;
		}
		y++;
	}
}

void	validate_map(t_data *data)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	count_elements(data, &player_count, &exit_count, &collectible_count);
	check_walls(data);
	if (player_count != 1 || exit_count != 1)
	{
		if (player_count != 1)
			ft_printf("Il doit y avoir que un joueur, trouvée: %d\n",
				player_count);
		if (exit_count != 1)
			ft_printf("Erreur: Il doit y avoir une sortie, trouvée: %d\n",
				exit_count);
		exit(1);
	}
	if (collectible_count < 1)
	{
		ft_printf("Erreur: Il doit y avoir au moins un collectible\n");
		exit(1);
	}
}
