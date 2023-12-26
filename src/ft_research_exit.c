/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_research_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilien <lilien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:43:48 by lauger            #+#    #+#             */
/*   Updated: 2023/12/26 15:35:37 by lilien           ###   ########.fr       */
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
        return (1);
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

int ft_research_object_exit(char **tab, t_position player, char c)
{
    t_position start;
    t_position destination;

    start.y = 0;
    start.x = 0;
    while (1)
    {
        destination = research_char(tab, start, c);
        if (destination.x == -1 && destination.y == -1)
            break;
        printf("%d\n",can_go_position(tab, player, destination));
        if (can_go_position(tab, player, destination) == -1)
            return (-1);
        start.x = destination.x + 1;
        start.y = destination.y;
    }
    return (1);
}

/*void *ft_calloc(int i, int j) {
    return malloc(i * j);
}
#include <stdio.h>
int main()
{

    char *map[] = {
        "11111111",
        "1P110101",
        "1111C101",
        "11100111",
        "11000101",
        "11000101",
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

    if (ft_research_object_exit(tab, player, 'C') == 1)
    {
        printf("chemin vers 'C' trouvé!\n");

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
        printf("Aucun chemin vers 'C' trouvé!\n");

    return 0;
}*/
