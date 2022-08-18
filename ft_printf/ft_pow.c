/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:13:12 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/11 15:17:50 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pow(int a, int b)
{
	int	i;

	i = a;
	if (b == 0)
		return (1);
	while (b != 1)
	{
		a *= i;
		b--;
	}
	return (a);
}

unsigned long long int	ft_pow_ull(unsigned long long int a,
							unsigned long long int b)
{
	unsigned long long int	i;

	i = a;
	if (b == 0)
		return (1);
	while (b != 1)
	{
		a *= i;
		b--;
	}
	return (a);
}
