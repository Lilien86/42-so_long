/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:30:35 by lauger            #+#    #+#             */
/*   Updated: 2023/12/13 10:18:53 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void    ft_creat_tab(char *str)
{
    char **tab;
    int  n;
    int  cnt;

    n = 0;
    cnt = 0;
    tab = ft_split(str, '\n');
    while (tab[cnt] != NULL)
        cnt++;
    ft_check_map(cnt, &tab[n]);
}

int main(int ac, char **av)
{
    int fd;
    char *line;
    char *buf;

    if (ac != 2)
        return (0);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (-1);
    buf = ft_calloc(1, 1);
    line = get_next_line(fd);
    while (line != NULL)
    {
        buf = ft_strjoin(buf, line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    ft_creat_tab(buf);
    return (0);
}
