/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_mbx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:39:21 by lauger            #+#    #+#             */
/*   Updated: 2023/12/21 12:54:42 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void cleanup_resources(void *mlx, void *mlx_win, t_image *image_array)
{
    int i = 0;

    while (i < 5) {
        if (image_array[i].img != NULL)
            mlx_destroy_image(mlx, image_array[i].img);
        i++;
    }
    mlx_destroy_window(mlx, mlx_win);
    mlx_destroy_display(mlx);
    free(mlx);
}


static int ft_display(t_display_info *image_info, t_image *image_array)
{
    int dest_x = image_info->x * image_info->size_image;
    int dest_y = image_info->y * image_info->size_image;
    
    int i = 0;
    while (i < 5) {
        if (image_array[i].symbol == image_info->symbol) {
            mlx_put_image_to_window(image_info->mlx, image_info->mlx_win, image_array[i].img, dest_x, dest_y);
            return (0);
        }
        i++;
    }
    return (0);
}

static void ft_check_symbol(char **tab, t_display_info *image_info, t_image *image_array)
{
    image_info->y = 0;
    while (tab[image_info->y]) {
        image_info->x = 0;
        while (tab[image_info->y][image_info->x]) {
            image_info->symbol = tab[image_info->y][image_info->x];
            ft_display(image_info, image_array);
            image_info->x++;
        }
        image_info->y++;
    }
}

int     handle_keydown(int keycode, void *param)
{
    t_display_info *image_info = (t_display_info *) param;
    (void) image_info;

	if (keycode == 65307)
	{
		cleanup_resources(image_info->mlx, image_info->mlx_win, image_info->image_array);
		exit(0);
	}
    return 0;
}

int mbx_links(char **tab)
{
    void *mlx;
    void *mlx_win;
    t_display_info image_info;

    image_info.size_image = 50;
    mlx = mlx_init();
    if (tab == NULL)
        return (0);
    mlx_win = mlx_new_window(mlx, 1500, 1300, "So_long");
    image_info.image_array[0] = (t_image){mlx_xpm_file_to_image(mlx, "/nfs/homes/lauger/Documents/PROJECT/cercle 3/so_long/Pixelarium - GrassLands/Sprites/Tileset/sable_r.xpm", &image_info.size_image, &image_info.size_image), '1'};
    image_info.image_array[1] = (t_image){mlx_xpm_file_to_image(mlx, "/nfs/homes/lauger/Documents/PROJECT/cercle 3/so_long/Pixelarium - GrassLands/Sprites/Tileset/graise_r.xpm", &image_info.size_image, &image_info.size_image), '0'};
    image_info.image_array[2] = (t_image){mlx_xpm_file_to_image(mlx, "/nfs/homes/lauger/Documents/PROJECT/cercle 3/so_long/Pixelarium - GrassLands/Sprites/Tileset/graise2_r.xpm", &image_info.size_image, &image_info.size_image), 'C'};
    image_info.image_array[3] = (t_image){mlx_xpm_file_to_image(mlx, "/nfs/homes/lauger/Documents/PROJECT/cercle 3/so_long/Pixelarium - GrassLands/Sprites/Tileset/terre_r.xpm", &image_info.size_image, &image_info.size_image), 'E'};
    image_info.image_array[4] = (t_image){mlx_xpm_file_to_image(mlx, "/nfs/homes/lauger/Documents/PROJECT/cercle 3/so_long/Pixelarium - GrassLands/Sprites/Tileset/void_r.xpm", &image_info.size_image, &image_info.size_image), 'P'};
    image_info.mlx = mlx;
    image_info.mlx_win = mlx_win;

    ft_check_symbol(tab, &image_info, image_info.image_array);
    ft_free_tab(tab);

    mlx_hook(image_info.mlx_win, 2, (1L<<0), handle_keydown, &image_info);

    mlx_loop(mlx);
    cleanup_resources(mlx, mlx_win, image_info.image_array);
    return 0;
}