/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilien <lilien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:02:15 by lauger            #+#    #+#             */
/*   Updated: 2023/12/26 10:58:44 by lilien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int ft_error(const char *message)
{
	ft_printf("Error: %s\n", message);
	return -1;
}

static int	ft_single_EP(char **str)
{
	size_t nb_e;
	size_t nb_p;
	size_t i;
	size_t j;

	nb_e = 0;
	nb_p = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		if (nb_e > 1 || nb_p > 1)
			return ft_error("Map is not valid because there is an extra 'E' or 'P'.");
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
	return(0);

}

static int ft_square_wall(size_t size_y, char **str)
{
	size_t i = 0;

	while (str[0][i])
	{
		if (str[0][i] != '1')
			return ft_error("Map is not valid because it misses a wall at the top.");
		i++;
	}
	i = 0;
	while (str[size_y - 1][i])
	{
		if (str[size_y - 1][i] != '1')
			return ft_error("Map is not valid because it misses a wall at the bottom.");
		i++;
	}
	i = 0;
	while (((ft_strlen(str[i])) >= size_y) && (ft_strlen(str[i]) == ft_strlen(str[0])))
	{
		if (str[i][0] != '1' && str[i][ft_strlen(str[i]) - 1] != '1')
			return ft_error("Map is not valid because it misses a wall on the sides.");
		i++;
	}
	return 0;
}


int ft_check_map(size_t size_y, char **str)
{
	size_t i;
	size_t j;

	i = 0;
	size_t k = 0;
	while (str[k])
	{
		ft_printf("%d: %s\n",k, str[k]);
		k++;
	}
	while (str[i] != 0)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '0' && str[i][j] != '1' && str[i][j] != 'C' &&
				str[i][j] != 'E' && str[i][j] != 'P' && str[i][j] != '\0')
					return ft_error("The map does not contain the requested characters ");
			j++;
		}
		i++;
	}
	//t_position player = research_char(str, (t_position){0, 0}, 'P');
	if (ft_square_wall(size_y, str) == -1
		|| ft_single_EP(str) == -1/* || ft_research_object_exit(str, player, 'C')*/)
		return (-1);
	return (0);
}
