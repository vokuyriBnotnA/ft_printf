/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:45:12 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/11 15:18:22 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	ft_number_count_ull(unsigned long long n)
{
	unsigned long long int	i;

	i = 0;
	while (n != 0)
	{
		n /= (unsigned long long int) 16;
		i++;
	}
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
	{
		count += write(1, "0x", 2);
	}
	if (flags.zero)
		n -= 2;
	if (n <= 0)
		return (count);
	while (n && !flags.minus)
	{
		count += write(1, &c, 1);
		n--;
	}
	if (c == ' ')
	{
		count += write(1, "0x", 2);
	}
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

int	ft_printf_p(void *arg, struct s_printf flags)
{
	unsigned long long	un;
	char				*str;
	int					i;
	int					count;
	char				c;

	i = 0;
	un = (unsigned long long) arg;
	str = "0123456789abcdef";
	count = ft_number_count_ull(un) - 1;
	i += ft_print_char_before(flags.width - ft_number_count_ull(un) - 1, flags);
	if (un == 0)
	{
		i += write(1, "0", 1);
	}
	while (count != -1 && (unsigned long long) arg != 0)
	{
		c = str[un / ft_pow_ull(16, count)];
		i += write(1, &c, 1);
		un -= (un / ft_pow_ull(16, count)) * ft_pow_ull(16, count);
		count--;
	}
	un = (unsigned long long) arg;
	i += ft_print_char_after(flags.width - ft_number_count_ull(un) - 2, flags);
	return (i);
}
