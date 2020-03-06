/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:37:15 by esalorin          #+#    #+#             */
/*   Updated: 2020/01/27 16:09:09 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_check_precision(char *s, int i)
{
	int p;

	p = 0;
	if (s[i] >= '0' && s[i] <= '9')
		p = ft_atoi(&s[i]);
	return (p);
}

void		ft_check_flags(char *s, int *m)
{
	int i;

	i = 0;
	m[0] = -1;
	m[1] = -1;
	m[2] = -1;
	m[3] = -1;
	m[4] = -1;
	while (s[i] != '\0' && s[i] != '.' && (s[i] < '1' || s[i] > '9'))
	{
		if (s[i] == '#')
			m[0] = 1;
		else if (s[i] == '0')
			m[1] = 1;
		else if (s[i] == '+')
			m[2] = 1;
		else if (s[i] == '-')
			m[3] = 1;
		else if (s[i] == ' ')
			m[4] = 1;
		i++;
	}
}

int			ft_check_min(char *s)
{
	int min;
	int	a;

	min = 0;
	a = 0;
	while (s[a] != '\0' && s[a] != '.' && (s[a] < '1' || s[a] > '9'))
		a++;
	if (s[a] > '0' && s[a] <= '9')
		min = ft_atoi(&s[a]);
	return (min);
}

int			ft_print_flags(char *sub, va_list ap)
{
	int l;
	int res;

	res = 0;
	l = ft_strlen(sub) - 1;
	if (sub[l] == 'd' || sub[l] == 'i' || sub[l] == 'o' || sub[l] == 'u'
		|| sub[l] == 'x' || sub[l] == 'X')
		res = ft_dioux_flags(sub, l, ap);
	else if (sub[l] == 'f')
		res = ft_double_flags(sub, l, ap);
	else if (sub[l] == 'c' || sub[l] == '%' || sub[l] == 's' || sub[l] == 'p')
		res = ft_csp_flags(sub, l, ap);
	return (res);
}
