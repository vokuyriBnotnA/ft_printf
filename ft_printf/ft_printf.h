/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:16:00 by klemongr          #+#    #+#             */
/*   Updated: 2021/11/11 15:16:46 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

struct s_printf
{
	int	minus;
	int	zero;
	int	dot;
	int	width;
	int	plus;
	int	space;
	int	grid;
} flags;

int						ft_printf(const char *str, ...);
int						ft_printf_flags(const char *str, void *arg);
int						ft_printf_type(char s, void *n, struct s_printf flags);
int						ft_printf_pct(struct s_printf flags);
int						ft_printf_c(void *n, struct s_printf flags);
int						ft_printf_s(char *str, struct s_printf flags);
int						ft_printf_d(void *arg, struct s_printf flags);
int						ft_printf_u(void *arg, struct s_printf flags);
int						ft_printf_p(void *arg, struct s_printf flags);
int						ft_printf_x(void *arg, char x, struct s_printf flags);
int						ft_pow(int a, int b);
unsigned long long int	ft_pow_ull(unsigned long long int a,
							unsigned long long int b);

#endif