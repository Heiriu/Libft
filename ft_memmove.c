/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:53:41 by thbierne          #+#    #+#             */
/*   Updated: 2019/12/04 13:43:16 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*sdst;
	unsigned char	*ssrc;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	sdst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	if (sdst > ssrc)
		while (i < len)
		{
			sdst[len - 1] = ssrc[len - 1];
			len--;
		}
	else
		while (i < len)
		{
			sdst[i] = ssrc[i];
			i++;
		}
	return (dst);
}
