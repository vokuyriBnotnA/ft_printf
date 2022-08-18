/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:40:05 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/11 15:13:34 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_number_count_u(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= (unsigned int) 10;
		i++;
	}
	return (i);
}

static int	ft_sign(int space, int plus)
{
	int	i;

	i = 0;
	if (plus)
		i += write(1, "+", 1);
	if (space)
		i += write(1, " ", 1);
	return (i);
}

static int	ft_print_char_before(int n, struct s_printf flags)
{
	int		count;
	char	c;

	count = 0;
	c = ' ';
	if (!flags.minus && (flags.dot || flags.zero))
		c = '0';
	if (c == '0' || n <= 0)
		count += ft_sign(flags.space, flags.plus);
	if (n <= 0)
		return (count);
	n -= flags.plus - flags.space;
	while (n && !flags.minus)
	{
		count += write(1, &c, 1);
		n--;
	}
	if (c == ' ')
		count += ft_sign(flags.space, flags.plus);
	return (count);
}

static int	ft_print_char_after(int n, struct s_printf flags)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (i);
	while (n && flags.minus)
	{
		i += write(1, " ", 1);
		n--;
	}
	return (i);
}

int	ft_printf_u(void *arg, struct s_printf flags)
{
	int		n;
	int		i;
	int		count;
	char	c;

	i = 0;
	n = (unsigned int) arg;
	i += ft_print_char_before(flags.width - ft_number_count_u(n), flags);
	count = ft_number_count_u(n) - 1;
	if ((int) arg == 0)
		i += write(1, "0", 1);
	while (count != -1 && (int) arg != 0)
	{
		c = (unsigned) n / ft_pow_ull(10, count) + '0';
		i += write(1, &c, 1);
		n -= (c - '0') * ft_pow_ull(10, count);
		count--;
	}
	i += ft_print_char_after(flags.width - ft_number_count_u((int) arg), flags);
	return (i);
}
