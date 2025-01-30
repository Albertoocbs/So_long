#include "so_long.h"
#include "mlx/minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == ESC_KEY) // ESC pour quitter
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }

    if (keycode == W_KEY) // W (haut)
        move_player(data, data->player_x, data->player_y - 1);
    else if (keycode == S_KEY) // S (bas)
        move_player(data, data->player_x, data->player_y + 1);
    else if (keycode == A_KEY) // A (gauche)
        move_player(data, data->player_x - 1, data->player_y);
    else if (keycode == D_KEY) // D (droite)
        move_player(data, data->player_x + 1, data->player_y);

    draw_map(data); // Redessiner après le déplacement
    return (0);
}

char **read_map(const char *filename, int *rows, int *cols)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file");
        return NULL;
    }

    char **map = NULL;
    char buffer[1024]; // Taille maximale d'une ligne
    int row_count = 0;

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

int main(int argc, char **argv)
{
    t_data data;

    // Vérifie qu'un fichier de carte est passé en argument
    if (argc != 2)
    {
        printf("Usage: %s <map_file.ber>\n", argv[0]);
        return (1);
    }

    data.rows = 0;
    data.cols = 0;
    data.collected = 0;
    data.total_collectibles = 0;

    // Lire la carte passée en argument
    data.map = read_map(argv[1], &data.rows, &data.cols);
    if (!data.map)
    {
        printf("Error loading map: %s\n", argv[1]);
        return (1);
    }

    // Trouver la position initiale du joueur + nombre de collectibles
    int y = 0;
    while (y < data.rows)
    {
        int x = 0;
        while (x < data.cols)
        {
            if (data.map[y][x] == 'P')
            {
                data.player_x = x;
                data.player_y = y;
            }
            else if (data.map[y][x] == 'C')
                data.total_collectibles++;
            x++;
        }
        y++;
    }

    // Initialiser MiniLibX
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.cols * TILE_SIZE, data.rows * TILE_SIZE, "so_long");

    // Charger les images
    load_sprites(&data);

    // Afficher la carte
    draw_map(&data);

    // Gérer les touches
    mlx_key_hook(data.win_ptr, handle_keypress, &data);

    // Boucle MiniLibX
    mlx_loop(data.mlx_ptr);

    return (0);
}