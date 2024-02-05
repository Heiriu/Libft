/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:46:43 by thbierne          #+#    #+#             */
/*   Updated: 2019/12/04 13:40:54 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int pos;
	unsigned int i;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		pos = 0;
		while (haystack[i + pos] == needle[pos] && (i + pos) < len)
		{
			pos++;
			if (needle[pos] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (0);
}
