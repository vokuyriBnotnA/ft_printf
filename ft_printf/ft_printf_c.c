/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:50:58 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/10 20:51:38 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(char c, int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		return (0);
	while (n)
	{
		count += write(1, &c, 1);
		n--;
	}
	return (count);
}

int	ft_printf_c(void *n, struct s_printf flags)
{
	char	c;
	int		count;

	count = 0;
	c = (int) n;
	if (!flags.minus)
		count += ft_print_char(' ', flags.width - 1);
	count += write(1, &c, 1);
	if (flags.minus)
		count += ft_print_char(' ', flags.width - 1);
	return (count);
}
