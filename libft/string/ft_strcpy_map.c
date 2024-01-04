/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:31:21 by lilien            #+#    #+#             */
/*   Updated: 2024/01/04 13:54:10 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strcpy_map(char **original, int height, int width)
{
	char **cpy = ft_calloc(height , sizeof(char*));
	for (int i = 0; i < height; i++)
	{
		cpy[i] = ft_calloc((width + 1) , sizeof(char));
		strcpy(cpy[i], original[i]);
	}
	return cpy;
}
