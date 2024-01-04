/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_research_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:43:48 by lauger            #+#    #+#             */
/*   Updated: 2024/01/04 13:15:17 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	can_go_position(char **tab, t_position player, t_position destination);

static int	is_obstacle(char **tab, t_position player)
{
	if (tab[player.y][player.x] == '1')
		return (1);
	else
		return (0);
}

t_position	research_char(char **tab, t_position start, char c)
{
	t_position	find;
	int			x;
	int			y;

	find.y = -1;
	find.x = -1;
	y = start.y;
	while (tab[y] != NULL && y < (int)ft_strlen_map(tab))
	{
		x = start.x;
		while (tab[y][x] != '\0' && x < (int)ft_strlen(tab[y]))
		{
			if (tab[y][x] == c)
			{
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

/*static int	algo(char **tab, t_position player, t_position destination)
{
		if (can_go_position(tab, (t_position){player.x - 1, player.y},
			destination) != -1
		|| can_go_position(tab, (t_position){player.x + 1, player.y},
			destination) != -1
		|| can_go_position(tab, (t_position){player.x, player.y - 1},
			destination) != -1
		|| can_go_position(tab, (t_position){player.x, player.y + 1},
			destination) != -1)
	{
		tab[player.y][player.x] = 'I';
		return (1);
	}
	return (-1);
}*/

static int	can_go_position(char **tab, t_position player,
	t_position destination)
{
	if (player.x < 0 || player.y < 0 || tab[player.y] == NULL
		|| tab[player.y][player.x] == '\0'
			|| tab[player.y][player.x] == 'X')
		return (-1);
	if (is_obstacle(tab, player))
		return (-1);
	if ((player.x == destination.x) && (player.y == destination.y))
	{
		tab[player.y][player.x] = '#';
		return (1);
	}
	tab[player.y][player.x] = 'X';
	if (can_go_position(tab, (t_position){player.x - 1, player.y},
			destination) != -1
		|| can_go_position(tab, (t_position){player.x + 1, player.y},
			destination) != -1
		|| can_go_position(tab, (t_position){player.x, player.y - 1},
			destination) != -1
		|| can_go_position(tab, (t_position){player.x, player.y + 1},
			destination) != -1)
	{
		tab[player.y][player.x] = 'I';
		return (1);
	}
	tab[player.y][player.x] = '0';
	return (-1);
}

int	ft_research_object_exit(char **map, t_position player, char c)
{
	t_position	start;
	t_position	destination;
	char		**cpy_map;

	start.y = 0;
	start.x = 0;
	cpy_map = ft_strcpy_map(map, ft_strlen_map(map), ft_strlen(map[1]));
	while (1)
	{
		destination = research_char(cpy_map, start, c);
		if (destination.x == -1 && destination.y == -1)
			break ;
		if (can_go_position(cpy_map, player, destination) == -1)
			return (-1);
		start.x = destination.x + 1;
		start.y = destination.y;
	}
	ft_free_tab(cpy_map);
	return (1);
}
