/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:21:48 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/11 14:57:12 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_type(char s, void *n, struct s_printf flags)
{
	int	count;

	count = 0;
	if (flags.minus)
		flags.zero = 0;
	if (flags.plus)
		flags.space = 0;
	if (s == '%')
		count += ft_printf_pct(flags);
	if (s == 'c')
		count += ft_printf_c(n, flags);
	if (s == 's')
		count += ft_printf_s(n, flags);
	if (s == 'd' || s == 'i')
		count += ft_printf_d(n, flags);
	if (s == 'u')
		count += ft_printf_u(n, flags);
	if (s == 'p')
		count += ft_printf_p(n, flags);
	if (s == 'x' || s == 'X')
		count += ft_printf_x(n, s, flags);
	return (count);
}
