/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilien <lilien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:31:21 by lilien            #+#    #+#             */
/*   Updated: 2023/12/27 07:38:11 by lilien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_strcpy_map(char **original, int height, int width)
{
    char **cpy = ft_calloc(height , sizeof(char*));
    for (int i = 0; i < height; i++)
    {
        cpy[i] = ft_calloc((width + 1) , sizeof(char));
        strcpy(cpy[i], original[i]);
    }
    return cpy;
}
