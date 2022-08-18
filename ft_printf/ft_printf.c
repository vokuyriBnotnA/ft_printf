/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:12:29 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/11 03:39:08 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_pct(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '%')
		return (1);
	while (str[i])
	{
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
			|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
			return (0);
		if (str[i] == '%')
			return (i);
		i++;
	}
	return (0);
}

static int	ft_type(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
			|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
			return (i);
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	factor;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(factor, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_pct(&str[i + 1]))
		{
			count += ft_printf_flags(&str[i + 1], NULL);
			i += ft_pct(&str[i + 1]);
		}
		else if (str[i] == '%')
		{
			count += ft_printf_flags(&str[i + 1], va_arg(factor, void *));
			i += ft_type(&str[i]);
		}
		else if (str[i] != '%')
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(factor);
	return (count);
}
