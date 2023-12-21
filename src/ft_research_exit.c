/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_research_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:43:48 by lauger            #+#    #+#             */
/*   Updated: 2023/12/21 13:52:58 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int isObstacle(t_position player)
{
    if (map[player->y][player->x] == '1')
        return 1;
    else
        return 0;
}

int     research_thing(char tab**, t_position start, char c)
{
    t_position find;
    int isObstacle(t_position player)
{
    if (map[player->y][player->x] == '1')
        return 1;
    else
        return 0;
}

int     research_thing(char tab**, t_position start, char c)
{
    t_position find;
    
    find.y = 0;
    find.x = 0;
    while(tab[start->y])
    {
        start->x = 0;
        while (tab[start->y][start->x])
        {
            if (tab[start->y][start->x] == c)
            {
                find->y = start->y;
                find->x = start->x;
                return (find);
            }
            start->x;
        }
        start->y++;
    }
    return 0;
}

int canReachPosition(char **tab, t_position player, t_position destination)
{
    if (isObstacle(player))
        return 0;

    if ((player->x == destination->x) && (player->y == destination->y))
        return 1;

    tab[player->x][player->y] = 'X';
    if (canReachPosition(player->x - 1, player->y, destination->x, destination->y) ||
        canReachPosition(player->x + 1, player->y, destination->x, destination->y) ||
        canReachPosition(player->x, player->y - 1, destination->x, destination->y) ||
        canReachPosition(player->x, player->y + 1, destination->x, destination->y))
    {
        tab[currentX][currentY] = '0';
        return 1;
    }

    tab[player->x][player->y] = '0';
    return 0;
}

int     ft_research_object_exit(char **tab, t_position player)
{
    t_position start;
    t_position destination;

    start->y = 2;
    start->x = 0;
    destination = research_thing(tab, start, 'C');

}

    while(tab[start->y])
    {
        start->x = 0;
        while (tab[i][j])
        {
            if (tab[start->y][start->x] == c)
            {
                find->y = start->y;
                find->x = start->x;
                return (find);
            }
            start->x;
        }
        start->y++;
    }
    return 0;
}

int canReachPosition(char **tab, t_position player, t_position destination)
{
    if (isObstacle(player))
        return 0;

    if ((player->x == destination->x) && (player->y == destination->y))
        return 1;

    tab[player->x][player->y] = 'X';

    if (canReachPosition(player->x - 1, player->y, destination->x, destination->y) ||
        canReachPosition(player->x + 1, player->y, destination->x, destination->y) ||
        canReachPosition(player->x, player->y - 1, destination->x, destination->y) ||
        canReachPosition(player->x, player->y + 1, destination->x, destination->y))
    {
        tab[currentX][currentY] = '0';
        return 1;
    }

    map[player->x][player->y] = '0';
    return 0;
}

int     ft_research_object_exit(char **tab, t_position player)
{
    t_position start;
    t_position destination;

    start->y = 2;
    start->x = 0;
    destination = research_thing(tab, start, 'C');

}
