/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:30:35 by lauger            #+#    #+#             */
/*   Updated: 2023/12/12 13:02:00 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int main(int ac, char **av)
{
    int     fd;
    char    *line;
    char    *buf;

    if (ac != 2)
    {
        ft_printf("The program simply waits for the map\n");
        return 0;
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Error of opening file\n");
        return 1;
    }
    buf = ft_calloc(1, 1);
    line = get_next_line(fd);
    while (line != NULL)
    {
        buf = ft_strjoin(buf, line);
        free(line);
        line = get_next_line(fd);
    }
    ft_printf("%s\n", buf);
    free(buf); // Free the allocated buffer
    close(fd);

    return 0;
}
