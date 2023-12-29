/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_mbx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilien <lilien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:39:21 by lauger            #+#    #+#             */
/*   Updated: 2023/12/29 10:00:20 by lilien           ###   ########.fr       */
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

static int ft_display_case(t_display_info *image_info, t_image *image_array, t_position player, char symbol)
{
    if (!image_info || !image_array)
        ft_error("Null pointer passed to ft_display_case\n");
    int dest_x = player.x * image_info->size_image;
    int dest_y = player.y * image_info->size_image;

    int i = 0;
    while (i < 5)
    {
        if (!image_array[i].img)
            ft_error("Image not loaded at index\n");

        if (image_array[i].symbol == symbol)
        {
            mlx_put_image_to_window(image_info->mlx, image_info->mlx_win, image_array[i].img, dest_x, dest_y);
            return (0);
        }
        i++;
    }
    return (0);
}


static int ft_display(t_display_info *image_info, t_image *image_array)
{
    if (!image_info || !image_array)
        ft_error("Null pointer passed to ft_display\n");
    int dest_x = image_info->x * image_info->size_image;
    int dest_y = image_info->y * image_info->size_image;

    int i = 0;
    while (i < 5)
    {
        if (!image_array[i].img)
            ft_error("Image not loaded at index\n");
        if (image_array[i].symbol == image_info->symbol)
        {
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
        while (tab[image_info->y][image_info->x]){
            image_info->symbol = tab[image_info->y][image_info->x];
            ft_display(image_info, image_array);
            image_info->x++;
        }
        image_info->y++;
    }
}

int     handle_keydown(int keycode, void *param , char **tab)
{
    t_display_info *image_info = (t_display_info *) param;
    
    ft_printf("keycode : %d\n", keycode);
	if (keycode == 65307)
	{
		cleanup_resources(image_info->mlx, image_info->mlx_win, image_info->image_array);
		exit(0);
	}
    t_position player;
    player = research_char(tab, (t_position){0, 0}, 'P');
    if (keycode == 115)
    {
        tab[player.y][player.x] = '0';
        tab[player.y - 1][player.x] = 'P';
         ft_printf("x = %d, y = %d\n", player.x, player.y);
        ft_display_case(image_info, image_info->image_array, (t_position){player.x, player.y}, '0');
        ft_display_case(image_info, image_info->image_array, (t_position){player.x, player.y - 1}, 'P');

    }
    if (keycode == 122)
    {
        // add verification size
        ft_display_case(image_info, image_info->image_array, player, '0');
        ft_display_case(image_info, image_info->image_array, (t_position){player.x, player.y + 1}, 'P');
        tab[player.y][player.x] = '0';
        tab[player.y + 1][player.x] = 'P';
    }
    return 0;
}

int mbx_links(char **tab)
{
    void *mlx;
    void *mlx_win;
    t_display_info image_info;

    image_info.size_image = 100;
    mlx = mlx_init();
    if (tab == NULL)
        return (0);
    mlx_win = mlx_new_window(mlx, (100 * ft_strlen(tab[1])) ,(100 * ft_strlen_map(tab)) , "So_long");
    image_info.image_array[0] = (t_image){mlx_xpm_file_to_image(mlx, "/home/lilien/Documents/so_long/Pixelarium/Sprites/Tileset/sable_r.xpm", &image_info.size_image, &image_info.size_image), '1'};
    image_info.image_array[1] = (t_image){mlx_xpm_file_to_image(mlx, "/home/lilien/Documents/so_long/Pixelarium/Sprites/Tileset/graise_r.xpm", &image_info.size_image, &image_info.size_image), '0'};
    image_info.image_array[2] = (t_image){mlx_xpm_file_to_image(mlx, "/home/lilien/Documents/so_long/Pixelarium/Sprites/Tileset/graise2_r.xpm", &image_info.size_image, &image_info.size_image), 'C'};
    image_info.image_array[3] = (t_image){mlx_xpm_file_to_image(mlx, "/home/lilien/Documents/so_long/Pixelarium/Sprites/Tileset/terre_r.xpm", &image_info.size_image, &image_info.size_image), 'E'};
    image_info.image_array[4] = (t_image){mlx_xpm_file_to_image(mlx, "/home/lilien/Documents/so_long/Pixelarium/Sprites/Tileset/void_r.xpm", &image_info.size_image, &image_info.size_image), 'P'};
    image_info.mlx = mlx;
    image_info.mlx_win = mlx_win;

    ft_check_symbol(tab, &image_info, image_info.image_array);
    ft_free_tab(tab);
    image_info.map = tab;
    mlx_hook(image_info.mlx_win, 2, (1L<<0), handle_keydown, &image_info);

    mlx_loop(mlx);
    return 0;
}