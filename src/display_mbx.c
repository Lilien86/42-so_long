/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_mbx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:39:21 by lauger            #+#    #+#             */
/*   Updated: 2024/01/06 11:10:13 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	cleanup_resources(void *mlx, void *mlx_win, t_image *image_array)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (image_array[i].img != NULL)
			mlx_destroy_image(mlx, image_array[i].img);
		i++;
	}
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
}

static int	ft_display(t_display_info *image_info, t_image *image_array)
{
	int	dest_x;
	int	dest_y;	
	int	i;

	dest_x = image_info->x * image_info->size_image;
	dest_y = image_info->y * image_info->size_image;
	i = 0;
	while (i < 5)
	{
		if (image_array[i].symbol == image_info->symbol)
		{
			mlx_put_image_to_window(image_info->mlx, image_info->mlx_win,
				image_array[i].img, dest_x, dest_y);
			return (0);
		}
		i++;
	}
	return (0);
}

static void	ft_check_symbol(char **map, t_display_info *image_info,
	t_image *image_array)
{
	image_info->y = 0;
	while (map[image_info->y])
	{
		image_info->x = 0;
		while (map[image_info->y][image_info->x])
		{
			image_info->symbol = map[image_info->y][image_info->x];
			ft_display(image_info, image_array);
			image_info->x++;
		}
		image_info->y++;
	}
}

static int	init_image(t_display_info *image_info)
{
	image_info->image_array[0] = (t_image){mlx_xpm_file_to_image(
			image_info->mlx, "./Pixelarium/wall.xpm",
			&image_info->size_image, &image_info->size_image), '1'};
	image_info->image_array[1] = (t_image){mlx_xpm_file_to_image(
			image_info->mlx, "./Pixelarium/void.xpm",
			&image_info->size_image, &image_info->size_image), '0'};
	image_info->image_array[2] = (t_image){mlx_xpm_file_to_image(
			image_info->mlx, "./Pixelarium/conssomable.xpm",
			&image_info->size_image, &image_info->size_image), 'C'};
	image_info->image_array[3] = (t_image){mlx_xpm_file_to_image(
			image_info->mlx, "./Pixelarium/exit.xpm",
			&image_info->size_image, &image_info->size_image), 'E'};
	image_info->image_array[4] = (t_image){mlx_xpm_file_to_image(
			image_info->mlx, "./Pixelarium/char.xpm",
			&image_info->size_image, &image_info->size_image), 'P'};
	return (0);
}

int	mbx_links(char **tab)
{
	void			*mlx;
	void			*mlx_win;
	t_display_info	image_info;

	if (tab == NULL)
		return (0);
	image_info.size_image = 50;
	mlx = mlx_init();
	mlx_win = mlx_new_window
		(mlx, (50 * ft_strlen(tab[1])), (50 * ft_strlen_map(tab)), "So_long");
	image_info.mlx = mlx;
	image_info.mlx_win = mlx_win;
	init_image(&image_info);
	ft_check_symbol(tab, &image_info, image_info.image_array);
	image_info.map = tab;
	mlx_hook(image_info.mlx_win, 2, (1L << 0), handle_keydown, &image_info);
	mlx_loop(mlx);
	return (0);
}
