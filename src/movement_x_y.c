/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_x_y.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:46:57 by lauger            #+#    #+#             */
/*   Updated: 2024/01/06 11:07:58 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	counter_c(char **map)
{
	int	cnt;
	int	y;
	int	x;

	y = 0;
	x = 0;
	cnt = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				cnt++;
			x++;
		}
		y++;
	}
	return (cnt);
}

int	movement_y_down(int keycode, t_display_info *image_info,
	t_pos player)
{
	if (keycode == 119)
	{
		if (image_info->map[player.y - 1][player.x] == '1'
		|| (counter_c(image_info->map)
			!= 0 && image_info->map[player.y - 1][player.x] == 'E'))
			return (0);
		if (counter_c(image_info->map) == 0
			&& image_info->map[player.y - 1][player.x] == 'E')
		{
			cleanup_resources(image_info->mlx,
				image_info->mlx_win, image_info->image_array);
			exit(0);
		}
		image_info->map[player.y][player.x] = '0';
		image_info->map[player.y - 1][player.x] = 'P';
		ft_display_case(image_info, image_info->image_array,
			(t_pos){player.x, player.y}, '0');
		ft_display_case(image_info, image_info->image_array,
			(t_pos){player.x, player.y - 1}, 'P');
	}
	return (0);
}

int	movement_y_up(int keycode, t_display_info *image_info,
	t_pos player)
{
	if (keycode == 115)
	{
		if (image_info->map[player.y + 1][player.x] == '1'
			|| (counter_c(image_info->map) != 0
				&& image_info->map[player.y + 1][player.x] == 'E'))
			return (0);
		if (counter_c(image_info->map) == 0
			&& image_info->map[player.y + 1][player.x] == 'E')
		{
			cleanup_resources(image_info->mlx, image_info->mlx_win,
				image_info->image_array);
			exit(0);
		}
		image_info->map[player.y][player.x] = '0';
		image_info->map[player.y + 1][player.x] = 'P';
		ft_display_case(image_info, image_info->image_array,
			(t_pos){player.x, player.y}, '0');
		ft_display_case(image_info, image_info->image_array,
			(t_pos){player.x, player.y + 1}, 'P');
	}
	return (0);
}

int	movement_x_left(int keycode, t_display_info *image_info,
	t_pos player)
{
	if (keycode == 97)
	{
		if (image_info->map[player.y][player.x - 1] == '1'
			|| (counter_c(image_info->map) != 0
				&& image_info->map[player.y][player.x - 1] == 'E'))
			return (0);
		if (counter_c(image_info->map) == 0
			&& image_info->map[player.y][player.x - 1] == 'E')
		{
			cleanup_resources(image_info->mlx, image_info->mlx_win,
				image_info->image_array);
			exit(0);
		}
		image_info->map[player.y][player.x] = '0';
		image_info->map[player.y][player.x - 1] = 'P';
		ft_display_case(image_info, image_info->image_array,
			(t_pos){player.x, player.y}, '0');
		ft_display_case(image_info, image_info->image_array,
			(t_pos){player.x - 1, player.y}, 'P');
	}
	return (0);
}

int	movement_x_right(int keycode, t_display_info *image_info,
	t_pos player)
{
	if (keycode == 100)
	{
		if (image_info->map[player.y][player.x + 1] == '1'
			|| (counter_c(image_info->map) != 0
				&& image_info->map[player.y][player.x + 1] == 'E'))
			return (0);
		if (counter_c(image_info->map) == 0
			&& image_info->map[player.y][player.x + 1] == 'E')
		{
			cleanup_resources(image_info->mlx, image_info->mlx_win,
				image_info->image_array);
			exit(0);
		}
		image_info->map[player.y][player.x] = '0';
		image_info->map[player.y][player.x + 1] = 'P';
		ft_display_case(image_info, image_info->image_array,
			(t_pos){player.x, player.y}, '0');
		ft_display_case(image_info, image_info->image_array,
			(t_pos){player.x + 1, player.y}, 'P');
	}
	return (0);
}
