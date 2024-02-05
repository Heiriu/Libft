/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:57:45 by thbierne          #+#    #+#             */
/*   Updated: 2024/02/05 11:58:44 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	allocSpaceChar(long long int nbr, int base)
{
	int i;

	i = 1;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char *converter(long long int nbr, int base, char *table)
{
	int count;
	int i;

	count = allocSpaceChar(nbr, base);
	char *str = malloc(sizeof(char) * count + 1);
	i = count - 1;
	while (i >= 0)
	{
		str[i--] = table[nbr % base];
		nbr /= base;
	}
	str[count] == '\0';
	return (str);
}