/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilien <lilien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:39:21 by lauger            #+#    #+#             */
/*   Updated: 2023/12/18 14:30:29 by lilien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

/*void clear_image(t_data *img, int width, int height, int background_color)
{
    int y;
    int x;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width) 
        {
            my_mlx_pixel_put(img, x, y, background_color);
            x++;
        }
        y++;
    }
}*/

void draw_square(t_data *img, int x1, int y1, int x2, int y2, int color)
{
    int x = x1;
    while (x <= x2) {
        int y = y1;
        while (y <= y2) {
            my_mlx_pixel_put(img, x, y, color);
            y++;
        }
        x++;
    }
}

void    ft_display(int  type, int x, int y, int size_image, void *mlx_win, void *mlx)
{
    int dest_x = x * size_image;
    int dest_y = y * size_image;
    t_data  graise;
    t_data  vide;

    graise.img = mlx_xpm_file_to_image(mlx, "/home/lilien/Documents/42-so_long/Pixelarium - GrassLands/Pack content/Sprites/Tileset/wall_r.xpm", &size_image, &size_image);
    graise.addr = mlx_get_data_addr(graise.img, &graise.bits_per_pixel, &graise.line_length, &graise.endian);
    vide.img = mlx_xpm_file_to_image(mlx, "/home/lilien/Documents/42-so_long/Pixelarium - GrassLands/Pack content/Sprites/Tileset/void_r.xpm", &size_image, &size_image);
    vide.addr = mlx_get_data_addr(vide.img, &vide.bits_per_pixel, &vide.line_length, &vide.endian);

     if (type == 1)
    {
        mlx_put_image_to_window(mlx, mlx_win, graise.img, dest_x, dest_y);
    }
    else
        mlx_put_image_to_window(mlx, mlx_win, vide.img, dest_x, dest_y);

}

int mbx_links(char **tab)
{
    void    *mlx;
    void    *mlx_win;
    int     size_image;
    int     i;
    int     j;

    size_image = 75;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1300, 1000, "So_long");
    i = 0;
    if (tab == 0)
        return (0);
    while(tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (tab[i][j] == '1')
                ft_display(1, j, i, size_image, mlx_win, mlx);
            else
                ft_display(0, j, i, size_image, mlx_win, mlx);
            j++;
        }
        i++;
    }
    mlx_loop(mlx);
    return 0;
}