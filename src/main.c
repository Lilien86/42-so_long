/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:30:35 by lauger            #+#    #+#             */
/*   Updated: 2024/01/07 09:03:01 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	check_file_extension(const char *filename)
{
	size_t	len;

	len = strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", ft_strlen(filename)) == 0)
		return (1);
	return (0);
}

static char	**ft_create_tab(char *str)
{
	char	**tab;
	int		n;
	int		cnt;

	n = 0;
	cnt = 0;
	tab = ft_split(str, '\n');
	while (tab[cnt] != NULL)
		cnt++;
	if (ft_check_map(cnt, &tab[n]) == -1)
	{
		ft_free_tab(tab);
		exit(0);
	}
	return (tab);
}

static int	manage_map(t_manage_map create_map)
{
	create_map.buf = ft_calloc(1, 1);
	create_map.line = get_next_line(create_map.fd);
	while (create_map.line != NULL)
	{
		create_map.tmp = ft_strjoin(create_map.buf, create_map.line);
		create_map.buf = create_map.tmp;
		free(create_map.line);
		create_map.line = get_next_line(create_map.fd);
	}
	close(create_map.fd);
	if (create_map.line != NULL)
		free(create_map.line);
	create_map.tab = ft_create_tab(create_map.buf);
	free(create_map.buf);
	if (create_map.tab != NULL)
		mbx_links(create_map.tab);
	return (0);
}

int	main(int ac, char **av)
{
	t_manage_map	create_map;

	if (ac != 2)
		return (0);
	if (check_file_extension(av[1]) == 0)
		return (ft_error("Map is not valid because a format is not good"));
	create_map.fd = open(av[1], O_RDONLY);
	if (create_map.fd == -1)
	{
		perror("Error at open the file");
		return (0);
	}
	manage_map(create_map);
	return (0);
}
