# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 14:42:36 by aoutumur          #+#    #+#              #
#    Updated: 2025/02/03 12:55:28 by aoutumur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c draw_map.c load_sprites.c move_player.c read_map.c validate_map.c
OBJS = $(SRCS:.c=.o)

LIB_MLX = ./mlx/minilibx-linux/libmlx.a
MLX_FLAGS = -Lmlx/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd

MAP_DIR = maps/

all: $(LIB_MLX) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_MLX) $(MLX_FLAGS) $(INCLUDES) -o $(NAME)

$(LIB_MLX):
	@make -C mlx/minilibx-linux

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
