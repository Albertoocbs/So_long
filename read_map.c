/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:37:32 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/03 12:55:33 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/minilibx-linux/mlx.h"

char **read_map(const char *filename, int *rows, int *cols)
{
    FILE *file;
    char **map;
    char buffer[1024]; // Taille maximale d'une ligne
    int row_count;

    file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file");
        return NULL;
    }
    map = NULL;
    row_count = 0;
    while (fgets(buffer, sizeof(buffer), file))
    {
        if (*cols == 0)
            *cols = strlen(buffer) - 1; // Calculer la largeur sans '\n'

        map = realloc(map, sizeof(char *) * (row_count + 1));
        map[row_count] = malloc(*cols + 1);
        strncpy(map[row_count], buffer, *cols);
        map[row_count][*cols] = '\0'; // Supprimer le '\n'
        row_count++;
    }
    fclose(file);
    *rows = row_count;
    return map;
}