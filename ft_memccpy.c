/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:43:23 by thbierne          #+#    #+#             */
/*   Updated: 2019/11/27 11:49:56 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	j;

	j = c;
	i = 0;
	while (i < n)
	{
		*((unsigned char*)dst + i) = *((unsigned char*)src + i);
		if (*((unsigned char*)src + i) == j)
		{
			i++;
			return (dst + i);
		}
		i++;
	}
	return (NULL);
}
