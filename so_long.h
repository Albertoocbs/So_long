/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:55:43 by aoutumur          #+#    #+#             */
/*   Updated: 2025/02/12 13:08:36 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL '1'
# define PLAYER 'P'
# define FLOOR '0'
# define EXIT 'E'
# define COLLECTIBLE 'C'

# define WIDTH 64
# define HEIGHT 64

# define TILE_SIZE 64

# define ESC_KEY 65307
# define CLOSE_EVENT 17
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define UP_KEY 65362
# define DOWN_KEY 65364
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# include "ft_printf/ft_printf.h"
# include "mlx/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_img;
	void	*player_img;
	void	*floor_img;
	void	*exit_img;
	void	*collectible_img;
	void	*img_buffer;
	char	*img_buffer_addr;
	int		bits_per_pixel;
	int		map_width;
	int		map_height;
	int		collected;
	int		total_collectibles;
	int		exit_found;
	int		acc_collectibles;
	int		player_x;
	int		player_y;
	int		rows;
	int		cols;
	int		moves;
	char	**map;
}			t_data;

/*------------------load_sprites.c------------------- */
void		load_sprites(t_data *data);
/*--------------------draw_map.c--------------------- */
int			draw_map(t_data *data);
void		put_tile_to_window(t_data *data, int x, int y, char tile);
/*-------------------move_player.c------------------- */
void		move_player(t_data *data, int new_x, int new_y);
/*--------------------read_map.c--------------------- */
char		**read_map(const char *filename, int *rows, int *cols);
int			count_map_rows(const char *filename);
int			get_map_cols(const char *filename);
char		**allocate_map_grid(int rows, int cols);
void		fill_map_grid(char **map, int fd, int rows, int cols);
/*--------------------validate_map.c----------------- */
void		validate_map(t_data *data);
void		count_elements(t_data *data, int *player_count, int *exit_count,
				int *collectible_count);
void		check_walls(t_data *data);
void		check_dimensions(t_data *data);
void		check_line_validity(t_data *data, int y);
/*------------------------main.c--------------------- */
void		free_map(char **map, int rows);
void		destroy_and_exit(t_data *data);
/*--------------------init_game.c------------------- */
void		load_map(t_data *data, char *map_file);
void		find_player_and_collectibles(t_data *data);
void		init_minilibx(t_data *data);
void		init_game(t_data *data, char *map_file);
/*--------------------flood_fill.c-------------------*/
void		flood_fill(char **map, int x, int y, t_data *data);
char		**copy_map(t_data *data);
void		check_valid_path(t_data *data);
/*--------------------error_exit.c-------------------*/
void		free_and_exit(t_data *data);

#endif
