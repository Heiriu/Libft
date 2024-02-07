/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:57:56 by thbierne          #+#    #+#             */
/*   Updated: 2024/02/07 11:00:42 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int ifTypeChar(va_list parametersInfos)
{
	int count = 0;

	char d = (int) va_arg(parametersInfos, int);
	write(1, &d, 1);

	return (1);
}

int ifTypeStr(va_list parametersInfos)
{
	int count = 0;

	char *str = (char *) va_arg(parametersInfos, char *);
	while (str[count])
		write(1, &str[count++], 1);
	return (count);
}

int ifTypeInt(va_list parametersInfos)
{
	int count = 0;

	long int i = (long int) va_arg(parametersInfos, long int);
	char *cpy = converter(i, 10, "0123456789");
	while (cpy[count])
		write(1, &cpy[count++], 1);
	free(cpy);
	return (count);
}

int ifTypeUnInt(va_list parametersInfos)
{
	int count = 0;

	long int i = (long int) va_arg(parametersInfos, long int);
	if (i < 0)
	{
		i *= -1;
		i += 2147483647;
	}
	char *cpy = converter(i, 10, "0123456789");
	while (cpy[count])
		write(1, &cpy[count++], 1);
	free(cpy);
	return (count);
}

int ifTypeHexa(va_list parametersInfos, char c)
{
	int count = 0;

	long int i = (long int) va_arg(parametersInfos, long int);
	char *cpy;
	if (c == 'x')
		cpy = converter(i, 16, "0123456789abcdef");
	else
		cpy = converter(i, 16, "0123456789ABCDEF");
	while (cpy[count])
		write(1, &cpy[count++], 1);
	free(cpy);
	return (count);
}

int ifTypeP(va_list parametersInfos)
{
	int count = 0;

	long long int i = (long long int) va_arg(parametersInfos, long long int);
	char *cpy;
	if (i <= 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	cpy = converter(i, 16, "0123456789abcdef");
	write(1 ,"0x", 2);
	while (cpy[count])
		write(1, &cpy[count++], 1);
	free(cpy);
	return (count + 2);
}

int ifTypePourcent(va_list parametersInfos)
{
	write(1, "%", 1);
	return (1);
}







int	selectTypeConversion(char c, va_list parametersInfos)
{
	int count = 0;

	if (c == 'c')
		count = ifTypeChar(parametersInfos);
	else if (c == 's')
		count = ifTypeStr(parametersInfos);
	else if (c == 'i' || c == 'd')
		count = ifTypeInt(parametersInfos);
	else if (c == 'u')
		count = ifTypeUnInt(parametersInfos);
	else if (c == 'x' || c == 'X')
		count = ifTypeHexa(parametersInfos, c);
	else if (c == 'p')
		count = ifTypeP(parametersInfos);
	else if (c == '%')
		count = ifTypePourcent(parametersInfos);
	return (count);
}

int ft_printf(const char *str, ...)
{
	int i;
	int count;
	va_list parametersInfos;

	i = 0;
	count = 0;
	va_start(parametersInfos, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += selectTypeConversion(str[i++], parametersInfos);
		}
		else
		{
			write(1, &str[i++], 1);
			count++;
		}
	}
	va_end(parametersInfos);
	return (count);
}