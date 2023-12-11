/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:59:06 by lauger            #+#    #+#             */
/*   Updated: 2023/12/11 13:39:36 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "stdio.h"

int	main(void)
{
	void *mlx;
    void *win;

    mlx = mlx_init(); // Initialisation de MiniLibX
    win = mlx_new_window(mlx, 800, 600, "Ma Fenêtre"); // Création d'une fenêtre

    // La boucle mlx_loop permet de maintenir la fenêtre ouverte
    mlx_loop(mlx);
	return 0;

}
