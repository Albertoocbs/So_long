/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:15:17 by aoutumur          #+#    #+#             */
/*   Updated: 2025/01/29 18:19:59 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/minilibx-linux/mlx.h"

void move_player(t_data *data, int new_x, int new_y)
{
    if (data->map[new_y][new_x] == '1') // Mur, ne pas bouger
        return;

    if (data->map[new_y][new_x] == 'C') // Collectible ramassé
    {
        data->collected++;
        data->map[new_y][new_x] = '0'; // Remplace le collectible par du sol
        draw_map(data);
    }

    if (data->map[new_y][new_x] == 'E' && data->collected == data->total_collectibles)
    {
        printf("Bravo ! Vous avez gagné !\n");
        exit(0);
    }

    // Déplacer le joueur
    data->map[data->player_y][data->player_x] = '0'; // Ancienne position
    data->map[new_y][new_x] = 'P'; // Nouvelle position
    data->player_x = new_x;
    data->player_y = new_y;
}
