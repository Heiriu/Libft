/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:59:00 by thbierne          #+#    #+#             */
/*   Updated: 2024/02/07 11:00:42 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_allocmemory(char const *s1, char const *s2, char *copy)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		copy[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		copy[j] = s2[i];
		i++;
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*copy;

	if (!s1)
		return (0);
	if (!s2)
		return (0);
	i = 0;
	j = 0;
	copy = NULL;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	copy = malloc(sizeof(*copy) * (i + j + 1));
	if (copy == NULL)
		return (NULL);
	copy = ft_allocmemory(s1, s2, copy);
	return (copy);
}
