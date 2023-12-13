/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:02:15 by lauger            #+#    #+#             */
/*   Updated: 2023/12/13 13:48:48 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int ft_square_wall(size_t size_y, char **str)
{
    size_t     i;
	size_t		j;
    size_t     size_x;

    i = 0;
	j = 0;
    size_x = 0;
    while (str[0][i])
    {
        if (str[0][i] != '1')
			perror("map is not valide because he missies wall");
        i++;
    }
	i = 0;
	while (str[size_y - 1][i])
	{	
        if (str[size_y - 1][i] != '1')
			return(0);
        i++;
	}
	i = 0;
	while (((ft_strlen(str[i])) >= size_y) && (ft_strlen(str[i]) == ft_strlen(str[0]))) //revoir ca
	{
		if (str[i][0] != '1' && str[i][ft_strlen(str[i]) - 1] != '1')
		{
			ft_printf("map pas de mur coter");
			return(0);
		}
		i++;
	}
    return(0);
}

int ft_check_map(size_t size_y, char **str)
{
	size_t i;
    size_t j;

	i = 0;
    size_t k = 0;
    while (str[k])
    {
        printf("%zu: %s\n",k, str[k]);
        k++;
    }
    while (str[i] != 0)
    {
        j = 0;
        while (str[i][j])
	    {
		    if (str[i][j] != '0' && str[i][j] != '1' && str[i][j] != 'C' &&
				str[i][j] != 'E' && str[i][j] != 'P' && str[i][j] != '\0')
		    {
			    perror("map is not valid\n");
			    return 0;
		    }
		    j++;
	    }
        i++;
    }
	i = 0;
   	ft_square_wall(size_y, str);
	return (0);
}
