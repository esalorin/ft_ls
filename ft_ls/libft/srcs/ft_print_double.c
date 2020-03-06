/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:29:31 by esalorin          #+#    #+#             */
/*   Updated: 2020/01/27 16:09:03 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_more(char *s, int *m, int res)
{
	int i;

	i = 0;
	if (m[3] == 1)
		ft_putstr(s);
	if (m[1] == 1 && m[3] == -1)
	{
		if (s[i] == '-' || s[i] == '+' || s[i] == ' ')
			ft_putchar(s[i++]);
		while (m[5] > res++)
			write(1, "0", 1);
		ft_putstr(&s[i]);
	}
	if (m[1] == -1 || m[3] == 1)
	{
		while (m[5] > res++)
			write(1, " ", 1);
		if (m[3] == -1)
			ft_putstr(s);
	}
	return (res);
}

static int	ft_checkf(char *s, int res, int *m)
{
	char	*s1;
	char	*s2;

	res = ft_strlen(s);
	s2 = NULL;
	s1 = NULL;
	if (m[2] == 1 && s[0] != '-' && res++)
		s1 = ft_strjoin("+", s);
	else if (m[4] == 1 && m[2] == -1 && s[0] != '-' && res++)
		s1 = ft_strjoin(" ", s);
	s1 = (s1 == NULL) ? ft_strdup(s) : s1;
	if (m[0] == 1 && !(ft_strchr(s1, '.')) && res++)
		s2 = ft_strjoin(s1, ".");
	if (s2 == NULL)
		s2 = ft_strdup(s1);
	if (m[5] <= res)
		ft_putstr(s2);
	if (m[5] > res)
		res = ft_print_more(s2, m, res);
	free(s1);
	free(s2);
	return (res);
}

int			ft_double_flags(char *s, int i, va_list ap)
{
	int	l;
	int p;
	int	m[6];

	p = 6;
	l = 0;
	ft_check_flags(s, m);
	m[5] = ft_check_min(s);
	while (i-- > 0)
	{
		if (s[i] == 'l' || s[i] == 'L')
			l = (s[i] == 'l') ? 1 : 2;
		if (s[i] == '.')
			p = ft_check_precision(s, i + 1);
	}
	return (ft_print_double(ap, p, l, m));
}

int			ft_print_double(va_list ap, int p, int len, int *m)
{
	long double	d;
	char		*s;
	int			res;

	res = 0;
	if (len == 0 || len == 1)
	{
		d = va_arg(ap, double);
		s = ft_ftoa(d, p);
	}
	else
	{
		d = va_arg(ap, long double);
		s = ft_ftoa(d, p);
	}
	if (m[0] == 0)
	{
		ft_putstr(s);
		res = ft_strlen(s);
	}
	else
		res = ft_checkf(s, len, m);
	free(s);
	return (res);
}
