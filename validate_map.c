/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:23:53 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/03 13:32:22 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/minilibx-linux/mlx.h"

void    check_walls(t_data *data)
{
    int x;
    int y;

    // Vérifier la première et la dernière ligne
    x = 0;
    while (x < data->cols)
    {
        if (data->map[0][x] != WALL || data->map[data->rows - 1][x] != WALL)
        {
            printf("Erreur: La carte n'est pas entourée de murs !\n");
            exit(1);
        }
        x++;
    }
    // Vérifier la première et la dernière colonne
    y = 0;
    while (y < data->rows)
    {
        if (data->map[y][0] != WALL || data->map[y][data->cols - 1] != WALL)
        {
            printf("Erreur: La carte n'est pas entourée de murs !\n");
            exit(1);
        }
        y++;
    }
}

void    count_elements(t_data *data, int *player_count, int *exit_count, int *collectible_count)
{
    int y = 0;
    while (y < data->rows)
    {
        int x = 0;
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

void    validate_map(t_data *data)
{
    int player_count;
    int exit_count;
    int collectible_count;

    player_count = 0;
    exit_count = 0;
    collectible_count = 0;
    count_elements(data, &player_count, &exit_count, &collectible_count);
    check_walls(data);
    if (player_count != 1)
    {
        printf("Erreur: Il doit y avoir un seul joueur ('P'), trouvé : %d\n", player_count);
        exit(1);
    }
    if (exit_count != 1)
    {
        printf("Erreur: Il doit y avoir une seule sortie ('E'), trouvée : %d\n", exit_count);
        exit(1);
    }
    if (collectible_count < 1)
    {
        printf("Erreur: Il doit y avoir au moins un collectible ('C')\n");
        exit(1);
    }
}

