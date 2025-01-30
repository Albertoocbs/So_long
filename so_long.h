/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:55:43 by aoutumur          #+#    #+#             */
/*   Updated: 2025/01/29 18:17:10 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL 1
# define PLAYER 2
# define FLOOR 3
# define EXIT 4
# define COLLECTIBLE 5

# define WIDTH 32
# define HEIGHT 32

#define ESC_KEY 65307
#define LEFT_KEY 65361
#define RIGHT_KEY 65363
#define UP_KEY 65362
#define DOWN_KEY 65364
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100

# define TILE_SIZE 32

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "mlx/minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *wall_img;
    void    *player_img;
    void    *floor_img;
    void    *exit_img;
    void    *collectible_img;
    int     map_width;
    int     map_height;
    int     collected;
    int     total_collectibles;
    int     player_x;
    int     player_y;
    int     rows;
    int     cols;
    char    **map;
}   t_data;

void    load_sprites(t_data *data);
void    draw_map(t_data *data);
void move_player(t_data *data, int new_x, int new_y);
void apply_transparency(void *img, int width, int height);

#endif