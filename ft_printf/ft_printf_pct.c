/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:46:42 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/11 02:23:26 by klemongr         ###   ########.fr       */
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

int	ft_printf_pct(struct s_printf flags)
{
	int		count;

	count = 0;
	if (!flags.minus)
		count += ft_print_char(' ', flags.width - 1);
	count += write(1, "%", 1);
	if (flags.minus)
		count += ft_print_char(' ', flags.width - 1);
	return (count);
}
