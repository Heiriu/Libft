/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:44:07 by thbierne          #+#    #+#             */
/*   Updated: 2019/12/12 08:50:50 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*srccpy;

	srccpy = dest;
	++n;
	while (--n > 0 && *src != '\0')
	{
		*dest++ = *src++;
	}
	while (n-- > 0 && *dest != '\0')
	{
		*dest = '\0';
		++dest;
	}
	return (srccpy);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		if (!(tab = ft_strnew(1)))
			return (0);
		return (tab);
	}
	i = 0;
	while (s[start + i] && i < len)
		i++;
	if (!(tab = ft_strnew(i)))
		return (0);
	ft_strncpy(tab, &s[start], len);
	return (tab);
}
