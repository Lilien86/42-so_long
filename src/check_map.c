/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:02:15 by lauger            #+#    #+#             */
/*   Updated: 2024/01/12 01:11:49 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_error(const char *message)
{
	ft_printf("Error: %s\n", message);
	return (-1);
}

static int	ft_single_ep(char **str)
{
	size_t	has_item[3];
	t_pos	navigation;

	has_item[0] = 0;
	has_item[1] = 0;
	has_item[2] = 0;
	navigation.y = 0;
	while (str[navigation.y])
	{
		navigation.x = 0;
		while (str[navigation.y][navigation.x])
		{
			if (str[navigation.y][navigation.x] == 'E')
				has_item[0]++;
			else if (str[navigation.y][navigation.x] == 'P')
				has_item[1]++;
			else if (str[navigation.y][navigation.x] == 'C')
				has_item[2]++;
			navigation.x++;
		}
		navigation.y++;
	}
	if (has_item[0] != 1 || has_item[1] != 1 || has_item[2] < 1)
		return (-1);
	return (0);
}

static int	ft_square_wall(size_t size_y, char **map)
{
	t_pos	p;

	p.y = 0;
	while (map[p.y])
	{
		p.x = 0;
		if (!((ft_strlen(map[p.y])) >= 3 || size_y >= 3))
			return (-1);
		while (map[p.y][p.x])
		{
			if ((p.y == 0 || p.y == (int)size_y -1
				|| p.x == 0 || p.x == (int)ft_strlen(map[p.y]) - 1)
				&& map[p.y][p.x] != '1')
				return (-1);
			if (ft_strlen(map[p.y]) != ft_strlen(map[0]))
				return (-1);
			p.x++;
		}
		p.y++;
	}
	return (0);
}

static int	manage_error(size_t size_y, char **str, t_pos player)
{
	if (ft_square_wall(size_y, str) == -1)
	{
		ft_printf("Error:\ninvalid map: the size is wrong\n");
		return (-1);
	}
	else if (ft_single_ep(str) == -1)
	{
		ft_printf("Error:\ninvalid map: missing or too many elements\n");
		return (-1);
	}
	else if (ft_research_object_exit(str, player, 'C') == -1)
	{
		ft_printf("Error:\ninvalid map: consumables is not accesible\n");
		return (-1);
	}
	else if (ft_research_object_exit(str, player, 'E') == -1)
	{
		ft_printf("Error:\ninvalid map: exit is not accesible\n");
		return (-1);
	}
	else
		return (0);
}

int	ft_check_map(size_t size_y, char **map)
{
	size_t		i;
	size_t		j;
	t_pos		player;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '\r')
			{
				ft_printf("Error:\ninvalid map: missing required characters\n");
				return (-1);
			}
			else
				j++;
		}
		i++;
	}
	player = research_char(map, (t_pos){0, 0}, 'P');
	if (manage_error(size_y, map, player) == -1)
		return (-1);
	return (0);
}
