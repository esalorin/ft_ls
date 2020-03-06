/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dioux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 22:05:01 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/01/27 16:08:56 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_base(char c)
{
	if (c == 'u')
		return (10);
	else if (c == 'o')
		return (8);
	else
		return (16);
}

static int	ft_print_oux(unsigned long long u, char c, int f, int *m)
{
	char	*s;
	int		b;

	b = ft_check_base(c);
	if (f == 0)
		s = ft_itoa_unsigned((unsigned int)u, b, c);
	else if (f == 1)
		s = ft_itoa_unsigned((unsigned long)u, b, c);
	else if (f == 2)
		s = ft_itoa_unsigned(u, b, c);
	else if (f == 3)
		s = ft_itoa_base((unsigned short)u, b, c);
	else
		s = ft_itoa_base((unsigned char)u, b, c);
	if (m[0] == 0 || (m[0] == -1 && m[1] == -1 && m[2] == -1 && m[3] == -1 &&
	m[4] == -1 && m[5] == 1 && (m[6] == -1 || (m[6] == 0 && s[0] != '0'))))
	{
		ft_putstr(s);
		b = ft_strlen(s);
	}
	else
		b = ft_check_oux(s, c, m);
	free(s);
	return (b);
}

static int	ft_print_di(long long n, char c, int f, int *m)
{
	char	*s;
	int		res;

	if (f == 0)
		s = ft_itoa_base((int)n, 10, c);
	else if (f == 1)
		s = ft_itoa_base((long)n, 10, c);
	else if (f == 2)
		s = ft_itoa_base(n, 10, c);
	else if (f == 3)
		s = ft_itoa_base((short)n, 10, c);
	else
		s = ft_itoa_base((char)n, 10, c);
	if (m[0] == 0 || (m[0] == -1 && m[1] == -1 && m[2] == -1 && m[3] == -1 &&
	m[4] == -1 && m[5] <= 1 && (m[6] == -1 || (m[6] == 0 && s[0] != '0'))))
	{
		ft_putstr(s);
		res = ft_strlen(s);
		free(s);
		return (res);
	}
	res = ft_check_di(s, m);
	free(s);
	return (res);
}

int			ft_print_dioux(char c, va_list ap, int f, int *m)
{
	int					res;
	long long			n;
	unsigned long long	u;

	res = 0;
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
	{
		u = va_arg(ap, unsigned long long);
		if (u == 0 && (m[0] == -1 || (m[0] == 1 && (c == 'x' || c == 'X'))) &&
		m[5] <= 1 && m[6] == 0)
			return (0);
		res = ft_print_oux(u, c, f, m);
	}
	else
	{
		n = va_arg(ap, long long);
		if (n == 0 && m[0] != 0 && m[2] == -1 && m[5] <= 1 && m[6] == 0)
			return (0);
		res = ft_print_di(n, c, f, m);
	}
	return (res);
}
