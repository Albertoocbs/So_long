#include "so_long.h"
#include "mlx/minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int close_window(t_data *data) // Fermer avec le bouton X
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    printf("Vous avez fermé la fenêtre avec le bouton X\n");
    exit(0);
    return (0);
}

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == ESC_KEY) // ESC pour quitter
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        printf("Vous avez ferme la fenetre avec ESC\n");
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
    else if (keycode == UP_KEY) // UP (haut)
        move_player(data, data->player_x, data->player_y - 1);
    else if (keycode == DOWN_KEY) // DOWN (bas)
        move_player(data, data->player_x, data->player_y + 1);
    else if (keycode == LEFT_KEY) // LEFT (gauche)
        move_player(data, data->player_x - 1, data->player_y);
    else if (keycode == RIGHT_KEY) // RIGHT (droite)
        move_player(data, data->player_x + 1, data->player_y);
    draw_map(data); // Redessiner après le déplacement
    return (0);
}

int main(int argc, char **argv)
{
    t_data  data;
    int     y;
    int     x;

    // Vérifie qu'un fichier de carte est passé en argument
    if (argc != 2)
    {
        printf("Aucun paramatre. Usage: %s <map_file.ber>\n", argv[0]);
        return (1);
    }
    data.rows = 0;
    data.cols = 0;
    data.collected = 0;
    data.total_collectibles = 0;
    data.moves = 0;
    // Lire la carte passée en argument
    data.map = read_map(argv[1], &data.rows, &data.cols);
    if (!data.map)
    {
        printf("Error loading map: %s\n", argv[1]);
        return (1);
    }
    validate_map(&data);
    y = 0; 
    while (y < data.rows)
    {// Trouver la position initiale du joueur + nombre de collectibles
        x = 0;
        while (x < data.cols)
        {
            if (data.map[y][x] == PLAYER)
            {
                data.player_x = x;
                data.player_y = y;
            }
            else if (data.map[y][x] == COLLECTIBLE)
                data.total_collectibles++;
            x++;
        }
        y++;
    }
    data.mlx_ptr = mlx_init();// Initialiser MiniLibX
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.cols * TILE_SIZE, data.rows * TILE_SIZE, "so_long");
    load_sprites(&data);// Charger les images
    draw_map(&data);// Afficher la carte
    mlx_key_hook(data.win_ptr, handle_keypress, &data);// Gérer les touches
    mlx_hook(data.win_ptr, CLOSE_EVENT, 0, close_window, &data);
    mlx_loop(data.mlx_ptr);// Boucle MiniLibX
    return (0);
}