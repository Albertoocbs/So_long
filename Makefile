# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 14:42:36 by aoutumur          #+#    #+#              #
#    Updated: 2025/02/05 12:22:48 by aoutumur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_DIR = ft_printf/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_FLAGS = -L$(FT_PRINTF_DIR) -lftprintf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c draw_map.c load_sprites.c move_player.c read_map.c validate_map.c init_game.c
OBJS = $(SRCS:.c=.o)

LIB_MLX = ./mlx/minilibx-linux/libmlx.a
MLX_FLAGS = -Lmlx/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd

MAP_DIR = maps/

all: $(LIBFT) $(FT_PRINTF) $(LIB_MLX) $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_MLX) $(MLX_FLAGS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(LIB_MLX):
	@make -C mlx/minilibx-linux

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean flclean re
