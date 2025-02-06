# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 19:03:06 by aoutumur          #+#    #+#              #
#    Updated: 2024/11/05 15:52:30 by aoutumur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_putchar_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c \
       ft_strtrim.c ft_substr.c ft_split.c ft_itoa.c ft_striteri.c\

OBJS = 	$(SRCS:.c=.o)

CC = 	gcc

CFLAGS = -Wall -Wextra -Werror

all: 	$(NAME)

$(NAME):$(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: 	%.c libft.h
		$(CC) -c $< $(CFLAGS) -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
