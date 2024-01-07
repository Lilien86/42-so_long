/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:07 by lauger            #+#    #+#             */
/*   Updated: 2024/01/07 10:52:14 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_manage_map
{
	int		fd;
	char	*line;
	char	*buf;
	char	*tmp;
	char	**tab;
}	t_manage_map;

typedef struct s_image
{
	void	*img;
	char	symbol;
}	t_image;

typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_display_info {
	char			symbol;
	char			**map;
	unsigned int	moves;
	int				x;
	int				y;
	int				size_image;
	void			*mlx_win;
	void			*mlx;
	t_image			image_array[5];
}	t_display_info;

int				ft_check_map(size_t size_y, char **map);
int				ft_error(const char *message);
int				mbx_links(char **tab);
int				ft_research_object_exit(char **tab, t_pos player, char c);
t_pos			research_char(char **tab, t_pos start, char c);
void			cleanup_resources(void *mlx, void *mlx_win,
					t_image *image_array);
int				ft_display_case(t_display_info *image_info,
					t_image *image_array, t_pos player, char symbol);
int				handle_keydown(int keycode, void *param);

int				movement_y_down(int keycode, t_display_info *image_info,
					t_pos player);
int				movement_y_up(int keycode, t_display_info *image_info,
					t_pos player);
int				movement_x_left(int keycode, t_display_info *image_info,
					t_pos player);
int				movement_x_right(int keycode, t_display_info *image_info,
					t_pos player);

#endif
