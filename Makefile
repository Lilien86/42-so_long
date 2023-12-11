# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lauger <lauger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 09:46:39 by lauger            #+#    #+#              #
#    Updated: 2023/12/11 14:10:25 by lauger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./libft
LIBFT_LIBRARY = $(LIBFT)/libft.a

MLX_PATH = mlx
MLX = -L $(MLX_PATH) -Imlx -O3

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT)
LDFLAGS = -L $(LIBFT) -lft

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_LIBRARY):
	$(MAKE) -C $(LIBFT)

$(NAME): $(LIBFT_LIBRARY) $(OBJ)
	$(CC) $(OBJ) $(MLX) $(LDFLAGS) -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(LIBFT) -c $< -o $@
clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(NAME)

fclean: clean
	$(MAKE) -C $(LIBFT) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

