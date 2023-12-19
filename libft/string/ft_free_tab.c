/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilien <lilien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:26:20 by lauger            #+#    #+#             */
/*   Updated: 2023/12/19 14:32:14 by lilien           ###   ########.fr       */
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