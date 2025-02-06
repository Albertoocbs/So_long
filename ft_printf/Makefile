# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 14:20:18 by aoutumur          #+#    #+#              #
#    Updated: 2025/01/15 07:47:47 by aoutumur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = 	ft_printf.c \
      	ft_print_char.c \
     	ft_print_str.c \
      	ft_print_ptr.c \
      	ft_print_unsigned.c \
      	ft_print_nbr.c \
      	ft_print_hex.c \
      	ft_print_percent.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar rc $(NAME) $(OBJS)
	ar x $(LIBFT)  
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm -f *.o 


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re





