/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:30:35 by lauger            #+#    #+#             */
/*   Updated: 2024/01/05 11:35:15 by lauger           ###   ########.fr       */
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

static char	**ft_creat_tab(char *str)
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

static int	manage_map(t_manage_map all)
{
	all.buf = ft_calloc(1, 1);
	all.line = get_next_line(all.fd);
	while (all.line != NULL)
	{
		all.tmp = ft_strjoin(all.buf, all.line);
		all.buf = all.tmp;
		free(all.line);
		all.line = get_next_line(all.fd);
	}
	close(all.fd);
	if (all.line != NULL)
		free(all.line);
	all.tab = ft_creat_tab(all.buf);
	free(all.buf);
	if (all.tab != NULL)
		mbx_links(all.tab);
	ft_free_tab(all.tab);
	return (0);
}

int	main(int ac, char **av)
{
	t_manage_map	all;

	// ac = 2;
	// av[1] = "../maps/map01.ber";

	if (ac != 2)
		return (0);
	if (check_file_extension(av[1]) == 0)
		return (ft_error("Map is not valid because a format is not good"));
	all.fd = open(av[1], O_RDONLY);
	if (all.fd == -1)
	{
		perror("Error at open the file");
		return (0);
	}
	manage_map(all);
	return (0);
}
