/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:51:20 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/11 15:13:25 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_number_count_x(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= (unsigned) 16;
		i++;
	}
	return (i);
}

static int	ft_print_grid(char x)
{
	write(1, "0", 1);
	write(1, &x, 1);
	return (2);
}

static int	ft_print_char_before(int n, struct s_printf flags, char x)
{
	int		count;
	char	c;

	count = 0;
	c = ' ';
	if (!flags.minus && (flags.dot || flags.zero))
		c = '0';
	if (flags.grid && (c == '0' || n <= 0))
		count += ft_print_grid(x);
	if (flags.grid)
		n -= 2;
	if (n <= 0)
		return (count);
	n -= flags.grid;
	while (n && !flags.minus)
	{
		count += write(1, &c, 1);
		n--;
	}
	if (flags.grid && c == ' ')
		count += ft_print_grid(x);
	return (count);
}

static int	ft_print_char_after(int n, struct s_printf flags)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (i);
	n -= flags.grid;
	while (n && flags.minus)
	{
		i += write(1, " ", 1);
		n--;
	}
	return (i);
}

int	ft_printf_x(void *arg, char x, struct s_printf flags)
{
	unsigned int	un;
	char			*str;
	int				i;
	int				count;

	i = 0;
	un = (unsigned int) arg;
	str = "0123456789abcdef";
	if (x == 'X')
		str = "0123456789ABCDEF";
	count = ft_number_count_x(un) - 1;
	if (un == 0)
		flags.grid = 0;
	i += ft_print_char_before(flags.width - ft_number_count_x(un), flags, x);
	if (un == 0)
		i += write(1, "0", 1);
	while (count != -1 && (unsigned int) arg != 0)
	{
		i += write(1, &str[un / ft_pow(16, count)], 1);
		un -= (un / ft_pow(16, count)) * ft_pow(16, count);
		count--;
	}
	un = (unsigned int) arg;
	i += ft_print_char_after(flags.width - ft_number_count_x(un), flags);
	return (i);
}
