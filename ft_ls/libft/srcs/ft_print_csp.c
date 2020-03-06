/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:45:08 by esalorin          #+#    #+#             */
/*   Updated: 2020/01/27 16:08:47 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_sp(char *s, int min, int max, int flag)
{
	int		len;
	char	*s1;

	s1 = NULL;
	len = ft_strlen(s);
	if (len == 0 && min == 0)
		return (0);
	if ((max > 0 || max == -1) && len > max)
	{
		if (max == -1)
			s1 = ft_strnew(0);
		else
			s1 = ft_strsub(s, 0, max);
		len = (max == -1) ? 0 : max;
	}
	s1 = (s1 == NULL) ? ft_strdup(s) : s1;
	if (flag == 1)
		ft_putstr(s1);
	while (min > len++)
		write(1, " ", 1);
	if (flag == 0)
		ft_putstr(s1);
	free(s1);
	return (len - 1);
}

static int	ft_check_c(char c, int min, int flag)
{
	int min2;

	min2 = (min == 0) ? 1 : min;
	if (min == 1 || min == 0)
		write(1, &c, 1);
	else
	{
		if (flag == 1)
			write(1, &c, 1);
		while (--min > 0)
			write(1, " ", 1);
		if (flag == 0)
			write(1, &c, 1);
	}
	return (min2);
}

int			ft_csp_flags(char *s, int l, va_list ap)
{
	int		m[2];
	int		flag;
	char	c;

	flag = 0;
	m[0] = 0;
	m[1] = -2;
	c = s[l];
	while (l-- > 0)
	{
		if (s[l] == '.')
		{
			m[1] = ft_check_precision(s, l + 1);
			if (m[1] == 0)
				m[1] = -1;
		}
		else if (s[l] == '-')
			flag = 1;
	}
	m[0] = ft_check_min(s);
	if (c == '%')
		return (ft_check_c(c, m[0], flag));
	return (ft_print_csp(c, ap, m, flag));
}

int			ft_print_csp(char c, va_list ap, int *m, int flag)
{
	long long	res;
	char		*temp;
	char		*s;

	if (c == 'c')
	{
		c = va_arg(ap, int);
		res = ft_check_c(c, m[0], flag);
	}
	else if (c == 's')
	{
		s = va_arg(ap, char*);
		s = (s == NULL) ? "(null)" : s;
		res = ft_check_sp(s, m[0], m[1], flag);
	}
	else
	{
		res = va_arg(ap, long long);
		temp = ft_itoa_base(res, 16, c);
		s = ft_strjoin("0x", temp);
		res = ft_check_sp(s, m[0], 0, flag);
		free(s);
		free(temp);
	}
	return (res);
}
