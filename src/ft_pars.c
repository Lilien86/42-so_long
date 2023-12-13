/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:30:35 by lauger            #+#    #+#             */
/*   Updated: 2023/12/13 07:22:44 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int ft_valid_or_not(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C' &&
			str[i] != 'E' && str[i] != 'P' && str[i] != '\n' && str[i] != '\0')
		{
			ft_printf("map is not valid");
			return 0;
		}
		i++;
	}
	ft_printf("map is valid");
	return 1;
}

int main(int ac, char **av)
{
	int fd;
	char *line;
	char *buf;

	if (ac != 2)
	{
		ft_printf("The program simply waits for the map\n");
		return 0;
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Error of opening file\n");
        return 1;
    }
    buf = ft_calloc(1, 1);
    line = get_next_line(fd);
    while (line != NULL)
    {
        buf = ft_strjoin(buf, line);
        free(line);
        line = get_next_line(fd);
    }
    ft_printf("%s\n", buf);
    close(fd);
    ft_valid_or_not(buf);
    return 0;
}
