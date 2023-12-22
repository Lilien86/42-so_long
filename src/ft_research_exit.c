/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_research_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:43:48 by lauger            #+#    #+#             */
/*   Updated: 2023/12/22 14:00:42 by lauger           ###   ########.fr       */
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

/*int     reset_map(char **tab)
{
    int     i;
    int     j;

    i = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (tab[i][j] == 'X')
                tab[i][j] = '0';
            j++;
        }
        i++;
    }
    return (0);
}*/

t_position     research_thing(char **tab, t_position start, char c)
{
    t_position find;

    find.y = -1;
    find.x = -1;
    while(tab[start.y])
    {
        start.x = 0;
        while (tab[start.y][start.x])
        {
            if (tab[start.y][start.x] == c)
            {
                find.y = start.y;
                find.x = start.x;
                return (find);
            }
            start.x++;
        }
        start.y++;
    }
     return (find);
}

int     canReachPosition(char **tab, t_position player, t_position destination)
{
    if (isObstacle(tab, player))
        return 0;

    if ((player.x == destination.x) && (player.y == destination.y))
        return 1;

    tab[player.y][player.x] = 'X';
    if (   canReachPosition(tab, (t_position){player.x - 1, player.y}, destination)
        || canReachPosition(tab, (t_position){player.x + 1, player.y}, destination)
        || canReachPosition(tab, (t_position){player.x, player.y - 1}, destination)
        || canReachPosition(tab, (t_position){player.x, player.y + 1}, destination))
    {
        tab[player.x][player.y] = '2';
        return 1;
    }

    tab[player.x][player.y] = '0';
    return (0);
}

int     ft_research_object_exit(char **tab, t_position player)
{
    t_position start;
    t_position destination;

    start.y = 2;
    start.x = 0;
    destination = research_thing(tab, start, 'C');
    while (destination.x != -1 && destination.y != -1)
    {
        if (canReachPosition(tab, player, destination) == 1)
        {
            destination.x = player.x;
            destination.y = player.y;
        }
        else 
            return (0);
        destination = research_thing(tab, player, 'C');
    }
    return (1);
}

void *ft_calloc(int i, int j) {
    return malloc(i * j);
}

int main()
{

    char *map[] = {
        "11111111",
        "1P110101",
        "1C000001",
        "111C0101",
        "110C0101",
        "110C0101",
        "11111111"
    };

    char **tab = ft_calloc(8, sizeof(char *));
    for (int i = 0; i < 7; i++)
    {
        tab[i] = ft_calloc(9, sizeof(char));
        for (int j = 0; j < 9; j++)
            tab[i][j] = map[i][j];
    }
    tab[7] = NULL;

    t_position player = {1, 1};
    //t_position destination;
    //reset_map(map);

    if (ft_research_object_exit(tab, player))
    {
        printf("Chemin vers 'C' trouvé!\n");

        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; map[i][j]; j++)
            {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Aucun chemin vers 'C' trouvé!\n");
    }

    return 0;
}
