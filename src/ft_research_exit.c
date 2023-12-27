/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_research_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilien <lilien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:43:48 by lauger            #+#    #+#             */
/*   Updated: 2023/12/27 07:59:48 by lilien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int     isObstacle(char **tab, t_position player)
{
    if (tab[player.y][player.x] == '1')
        return 1;
    else
        return (0);
}

t_position research_char(char **tab, t_position start, char c)
{
    t_position find;

    find.y = -1;
    find.x = -1;

    int y = start.y;
    while (tab[y] != NULL)
    {
        int x = start.x;
        
        while (tab[y][x] != '\0')
        {
            if (tab[y][x] == c) {
                find.y = y;
                find.x = x;
                return (find);
            }
            x++;
        }
        y++;
        start.x = 0;
    }

    return (find);
}

int can_go_position(char **tab, t_position player, t_position destination)
{
    if (player.x < 0 || player.y < 0 || tab[player.y] == NULL || tab[player.y][player.x] == '\0' || tab[player.y][player.x] == 'X')
        return (-1);
    if (isObstacle(tab, player))
        return (-1);
    if ((player.x == destination.x) && (player.y == destination.y))
    {
        tab[player.y][player.x] = '#';
        return (1);
    }
    tab[player.y][player.x] = 'X';
    if (can_go_position(tab, (t_position){player.x - 1, player.y}, destination) != -1
        || can_go_position(tab, (t_position){player.x + 1, player.y}, destination) != -1
        || can_go_position(tab, (t_position){player.x, player.y - 1}, destination) != -1
        || can_go_position(tab, (t_position){player.x, player.y + 1}, destination) != -1)
    {
        tab[player.y][player.x] = 'I';
        return (1);
    }
    tab[player.y][player.x] = '0';
    return (-1);
}   

int ft_research_object_exit(char **map, t_position player, char c)
{
    t_position start;
    t_position destination;
    char       **cpy_map;

    start.y = 0;
    start.x = 0;
    cpy_map = ft_strcpy_map(map, ft_strlen_map(map), ft_strlen(map[1]));
    while (1)
    {
        destination = research_char(cpy_map, start, c);
        if (destination.x == -1 && destination.y == -1)
            break;
        printf("%d\n",can_go_position(cpy_map, player, destination));
        if (can_go_position(cpy_map, player, destination) == -1)
            return (-1);
        start.x = destination.x + 1;
        start.y = destination.y;
    }
    ft_free_tab(cpy_map);
    return (1);
}
