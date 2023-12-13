/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:02:15 by lauger            #+#    #+#             */
/*   Updated: 2023/12/13 09:08:26 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*int ft_is_surrounded_walls(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\n')
    {
        if (str[i] != '1')
        {
            printf("no wall above\n");
            return 0;
        }
        i++;
    }

    while (str[i])
    {
        if (str[i] == '\n' && str[i - 1] != '1' && str[i + 1] != '1')
        {
            printf("no wall on the coat\n");
            return 0;
        }
        i++;
    }

    printf("map is very valid\n");
    return (1); // Changed return value to indicate success
}*/


int ft_check_map(int size_y, char **str)
{
    void(size_y);
	int i;
    int j;

	i = 0;
    while (str[i] != '\0')
    {
        j = 0;
        while (str[i][j])
	    {
		    if (str[i][j] != '0' && str[i][j] != '1' && str[i][j] != 'C' &&
			str[i][j] != 'E' && str[i][j] != 'P' && str[i][j] != '\0')
		    {
			    ft_printf("map is not valid");
			    return 0;
		    }
		    j++;
	    }
        i++;
    }
	
	ft_printf("map is valid\n");
	//ft_is_surrounded_walls(str); 
	return 1;
}
