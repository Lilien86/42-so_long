/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:39:21 by lauger            #+#    #+#             */
/*   Updated: 2023/12/15 14:15:40 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int mbx_test(void)
{
    void *mlx;
    void *mlx_win;
    t_data img;
    int color = 0x0000FF00;
    int y = 0;
    int x = 0;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
    img.img = mlx_new_image(mlx, 800, 600);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    while (x < 100)
    {
        y = 0;
        while (y < 500)
        {
            my_mlx_pixel_put(&img, x, y, color);
            y++;
        }
		
        mlx_put_image_to_window(mlx, mlx_win, img.img, x, 0);
        //mlx_do_sync(mlx);
        //mlx_clear_window(mlx, mlx_win);
        usleep(50000);
        x++;
    }

    mlx_loop(mlx);

    return 0;
}