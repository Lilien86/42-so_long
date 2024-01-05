/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keydown.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:34:25 by lauger            #+#    #+#             */
/*   Updated: 2024/01/05 10:10:28 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_display_case(t_display_info *image_info,
	t_image *image_array, t_pos player, char symbol)
{
	int	dest_x;
	int	dest_y;	
	int	i;

	if (!image_info || !image_array)
		return (ft_error("Null pointer passed to ft_display_case\n"));
	dest_x = player.x * image_info->size_image;
	dest_y = player.y * image_info->size_image;
	i = 0;
	while (i < 5)
	{
		if (image_array[i].symbol == symbol)
		{
			mlx_put_image_to_window(image_info->mlx,
				image_info->mlx_win, image_array[i].img, dest_x, dest_y);
			return (0);
		}
		i++;
	}
	return (0);
}

int	handle_keydown(int keycode, void *param)
{
	t_display_info	*image_info;
	t_pos			player;

	image_info = (t_display_info *) param;
	if (image_info->map == NULL)
		return (ft_error("no map"));
	image_info = (t_display_info *) param;
	if (keycode == 65307)
	{
		cleanup_resources(image_info->mlx, image_info->mlx_win,
			image_info->image_array);
		exit(0);
	}
	player = research_char(image_info->map, (t_pos){0, 0}, 'P');
	movement_y_down(keycode, image_info, player);
	movement_y_up(keycode, image_info, player);
	movement_x_left(keycode, image_info, player);
	movement_x_right(keycode, image_info, player);
	return (0);
}
