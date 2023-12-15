/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:26:20 by lauger            #+#    #+#             */
/*   Updated: 2023/12/15 10:20:11 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void    ft_free_tab(char **str)
{
    int i;

    i = 0;
    if (str == NULL || *str == NULL)
        return ;
    while (str[i])
    {
        if (str[i] != NULL)
            free(str[i]);
        i++;
    }
    free(str);
}