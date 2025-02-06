/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:23:53 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/06 10:13:09 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/minilibx-linux/mlx.h"
#include "so_long.h"

void	check_line_validity(t_data *data, int y)
{
	int	x;
	int	line_length;

	x = 0;
	line_length = 0;
	while (data->map[y][x] != '\0')
	{
		if (data->map[y][x] != '\n')
			line_length++;
		x++;
	}
	if (line_length != data->cols)
	{
		ft_printf("Erreur: Dimensions de carte invalides\n");
		exit(1);
	}
}

void	check_dimensions(t_data *data)
{
	int	y;

	if (data->rows <= 0 || data->cols <= 0)
	{
		ft_printf("Erreur: Dimensions de carte invalides (0 ou négative)\n");
		exit(1);
	}
	y = 0;
	while (y < data->rows)
	{
		check_line_validity(data, y);
		y++;
	}
}

void	check_walls(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->cols)
	{
		if (data->map[0][x] != WALL || data->map[data->rows - 1][x] != WALL)
		{
			ft_printf("Erreur: La carte n'est pas entourée de murs!\n");
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

	check_dimensions(data);
	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	count_elements(data, &player_count, &exit_count, &collectible_count);
	check_walls(data);
	if (player_count != 1 || exit_count != 1)
	{
		if (player_count != 1)
			ft_printf("Erreur: Il doit y avoir un joueur, trouvée: %d\n",
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
