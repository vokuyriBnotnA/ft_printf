/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:52:03 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/11 14:50:30 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(int n, struct s_printf flags)
{
	int	count;

	count = 0;
	if (n <= 0 || flags.dot)
		return (0);
	while (n)
	{
		count += write(1, " ", 1);
		n--;
	}
	return (count);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (6);
	while (str[i])
		i++;
	return (i);
}

static int	ft_print_str(char *str, int width, int dot)
{
	int	i;

	i = 0;
	while (str[i] && (i < width || !dot))
	{
		i += write(1, &str[i], 1);
	}
	return (i);
}

int	ft_printf_s(char *str, struct s_printf flags)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!flags.minus)
		count += ft_print_char(flags.width - ft_strlen(str), flags);
	if (str == NULL)
		count += ft_print_str("(null)", flags.width, flags.dot);
	else
		count += ft_print_str(str, flags.width, flags.dot);
	if (flags.minus)
		count += ft_print_char(flags.width - ft_strlen(str), flags);
	return (count);
}
