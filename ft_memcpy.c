/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:00:26 by thbierne          #+#    #+#             */
/*   Updated: 2019/11/27 13:43:45 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	while (i < n)
	{
		*((unsigned char*)dst + i) = *((unsigned char*)src + i);
		i++;
	}
	return (dst);
}
