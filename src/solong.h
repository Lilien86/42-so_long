/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:07 by lauger            #+#    #+#             */
/*   Updated: 2023/12/21 13:15:37 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
#endif

typedef struct s_image
{
    void *img;
    char symbol;
} t_image;

typedef struct s_position
{
    int x;
    int y;
} t_position;

typedef struct s_display_info {
    char symbol;
    int x;
    int y;
    int size_image;
    void *mlx_win;
    void *mlx;
	t_image image_array[5];
} t_display_info;


#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mlx.h"
#include "libft.h"

int ft_check_map(size_t size_y, char **str);
int ft_error(const char *message);
int mbx_links(char **tab);

#endif
