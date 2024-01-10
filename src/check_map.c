/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:02:15 by lauger            #+#    #+#             */
/*   Updated: 2024/01/10 13:21:00 by lauger           ###   ########.fr       */
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
	size_t	nb_e;
	size_t	nb_p;
	size_t	i;
	size_t	j;

	nb_e = 0;
	nb_p = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		if (nb_e > 1 || nb_p > 1)
			return (-1);
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				nb_e++;
			else if (str[i][j] == 'P')
				nb_p++;
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_square_wall(size_t size_y, char **map )
{
	size_t	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != '\r')
			return (-1);
		i++;
	}
	i = 0;
	while (map[size_y - 1][i])
	{
		if (map[size_y - 1][i] != '1' && map[size_y - 1][i] != '\r'
			&& map[size_y - 1][i] != '\0')
			return (-1);
		i++;
	}
	i = 0;
	while (i < size_y - 1)
	{
		if ((map[i][0] != '1' && map[i][ft_strlen(map[i]) - 1] != '1')
			|| (!((ft_strlen(map[i])) >= size_y))
			|| (ft_strlen(map[i]) != ft_strlen(map[0])))
			{
				for(size_t p = 0; p < size_y; p++)
					ft_printf("%d: %s\n", p, map[p]);
				return (-1);
			}
		i++;
	}
	return (0);
}

static int	manage_error(size_t size_y, char **str, t_pos player)
{
	if (ft_square_wall(size_y, str) == -1)
	{
		ft_printf("map is not valide because the size is wrong");
		return (-1);
	}
	else if (ft_single_ep(str) == -1)
	{
		ft_printf
			("map is not valide because there are too many players or exits");
		return (-1);
	}
	else if (ft_research_object_exit(str, player, 'C') == -1)
	{
		ft_printf("map is not valide because the consumables is not accesible");
		return (-1);
	}
	else if (ft_research_object_exit(str, player, 'E') == -1)
	{
		ft_printf("map is not valide because the exit is not accesible");
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
				ft_printf("map not valide, not contain what is required");
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
