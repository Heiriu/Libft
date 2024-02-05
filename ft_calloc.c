/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:44:32 by thbierne          #+#    #+#             */
/*   Updated: 2019/12/03 15:05:31 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*pointer;
	size_t			i;

	i = 0;
	if (!(pointer = malloc(size * count)))
		return (0);
	while (i < (count * size))
	{
		pointer[i] = 0;
		i++;
	}
	return ((void *)pointer);
}
