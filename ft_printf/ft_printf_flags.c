/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:20:40 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/11 14:57:04 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_atoi(const char *str)
{
	int	j;
	int	res;

	j = 0;
	res = 0;
	while (str[j] && !ft_type_char(str[j]))
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			res *= 10;
			res += (str[j] - '0');
		}
		j++;
	}
	return (res);
}

static struct s_printf	ft_zero_struct(void)
{
	struct flags;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.width = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.grid = 0;
	return (flags);
}

int	ft_printf_flags(const char *str, void *arg)
{
	int	i;

	struct flags;
	flags = ft_zero_struct();
	flags.width = ft_atoi(str);
	i = 0;
	while (str[i] && !ft_type_char(str[i]))
	{
		if (str[i] == '-')
			flags.minus = 1;
		if (str[i] == '0' && flags.width == ft_atoi(&str[i + 1]))
			flags.zero = 1;
		if (str[i] == '.')
			flags.dot = 1;
		if (str[i] == '+')
			flags.plus = 1;
		if (str[i] == ' ')
			flags.space = 1;
		if (str[i] == '#')
			flags.grid = 2;
		i++;
	}
	return (ft_printf_type(str[i], arg, flags));
}
