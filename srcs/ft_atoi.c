/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:17:25 by thbierne          #+#    #+#             */
/*   Updated: 2024/02/07 11:00:42 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int				ft_get_retour(int retour, int somme, int signe)
{
	if (retour >= 20 && signe == -1)
		retour = 0;
	else if (retour >= 20 && signe == 1)
		retour = -1;
	else
		retour = somme * signe;
	return (retour);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		signe;
	int		somme;
	int		retour;

	retour = 0;
	i = 0;
	signe = 1;
	somme = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		somme = (somme * 10) + (str[i] - 48);
		i++;
		retour++;
	}
	return (ft_get_retour(retour, somme, signe));
}
