# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lauger <lauger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 09:46:39 by lauger            #+#    #+#              #
#    Updated: 2023/12/20 11:08:13 by lauger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./libft
LIBFT_LIBRARY = $(LIBFT)/libft.a

MLX_PATH = ./mlx
MLX = -L $(MLX_PATH) -Imlx -O3 -lmlx

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT)
LDFLAGS = -L $(LIBFT) -lft

SRC = ./src/ft_pars.c ./src/ft_check_map.c ./src/ft_display_mbx.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_LIBRARY):
	make --quiet -C $(LIBFT)  re

$(NAME): $(LIBFT_LIBRARY) $(OBJ)
	$(CC) $(OBJ) $(MLX) $(LDFLAGS) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(LIBFT) -c $< -o $@
clean:
	make --quiet -C $(LIBFT) clean
	rm -f $(NAME) $(OBJ)

fclean: clean
	make --quiet -C $(LIBFT) clean
	rm -f $(NAME) $(OBJ)

re: fclean all

gdb: CFLAGS += -g
gdb: fclean all

.PHONY: all clean fclean re
