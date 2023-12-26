/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilien <lilien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:30:35 by lauger            #+#    #+#             */
/*   Updated: 2023/12/26 13:34:55 by lilien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// I'm waiting (present progressif : be + -ing)

#include "solong.h"

static int check_file_extension(const char *filename)
{
    
	size_t len = strlen(filename);
    
    if (len < 5)
        return (0);
    if (ft_strncmp(filename + len - 4, ".txt", ft_strlen(filename)) == 0
        || ft_strncmp(filename + len - 4, ".ber", ft_strlen(filename)) == 0)
        return (1);
    return (0);
}

static char    **ft_creat_tab(char *str)
{
    char **tab;
    int  n;
    int  cnt;

    n = 0;
    cnt = 0;
    tab = ft_split(str, '\n');
    while (tab[cnt] != NULL)
        cnt++;
    if (ft_check_map(cnt, &tab[n]) == -1)
    {
        ft_free_tab(tab);
        return (NULL);
    }
    return (tab);
}

int main(int ac, char **av)
{
    int     fd;
    char    *line;
    char    *buf;
    char    *tmp;
    char    **tab;

    if (ac != 2)
        return (0);
    if(check_file_extension(av[1]) == 0)
        return ft_error("Map is not valid because a format is not good");
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
    	perror("Error at open the file");
    	return(0);
    }
    buf = ft_calloc(1, 1);
    line = get_next_line(fd);
    while (line != NULL)
    {
        tmp = ft_strjoin(buf, line);
        buf = tmp;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    if (line != NULL)
        free(line);
    tab = ft_creat_tab(buf);
    free(buf);
    if (tab != NULL)
        mbx_links(tab);
    return (0);
}
