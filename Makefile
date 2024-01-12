# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lauger <lauger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 09:46:39 by lauger            #+#    #+#              #
#    Updated: 2024/01/11 12:42:42 by lauger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./so_long

LIBFT = ./libft
LIBFT_LIBRARY = $(LIBFT)/libft.a

MLX_PATH = ./mlx
MLX_M = $(MLX_PATH)/libmlx_Linux.a

MLX = -L $(MLX_PATH) -Imlx -O3 -lmlx

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT)
LDFLAGS = -L $(LIBFT) -lft

SRC = ./src/main.c ./src/check_map.c ./src/display_mbx.c ./src/research_exit.c ./src/keydown.c ./src/movement_x_y.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_LIBRARY):
	make --quiet -C $(LIBFT)
$(MLX_M) :
	make --quiet -C $(MLX_PATH)

$(NAME): $(MLX_M) $(LIBFT_LIBRARY) $(OBJ)
	$(CC) $(OBJ) $(MLX) $(LDFLAGS) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(LIBFT) -c $< -o $@
clean:
	make --quiet -C $(MLX_PATH)
	make --quiet -C $(LIBFT) clean
	rm -f $(NAME) $(OBJ)

fclean: clean
	make --quiet -C $(LIBFT) clean
	rm -f $(NAME) $(OBJ)

re: fclean all

gdb: CFLAGS += -g
gdb: fclean all

.PHONY: all clean fclean re
