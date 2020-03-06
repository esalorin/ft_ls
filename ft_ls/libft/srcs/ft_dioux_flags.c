/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dioux_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:22:59 by esalorin          #+#    #+#             */
/*   Updated: 2020/01/27 16:09:38 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dioux_llhh(int lh, char c, va_list ap, int *m)
{
	int res;

	res = 0;
	if (lh == 0)
		res = ft_print_dioux(c, ap, 0, m);
	else if (lh == 1)
		res = ft_print_dioux(c, ap, 1, m);
	else if (lh == 2)
		res = ft_print_dioux(c, ap, 2, m);
	else if (lh == 3)
		res = ft_print_dioux(c, ap, 3, m);
	else
		res = ft_print_dioux(c, ap, 4, m);
	return (res);
}

int			ft_dioux_flags(char *s, int i, va_list ap)
{
	int		lh;
	int		m[7];
	char	c;

	lh = 0;
	c = s[i];
	ft_check_flags(s, m);
	if (!(m[5] = ft_check_min(s)))
		m[5] = 1;
	m[6] = -1;
	while (i-- > 0)
	{
		if (s[i] == '.')
			m[6] = ft_check_precision(s, i + 1);
		if (s[i] == 'l' && (lh == 0 || lh == 1))
			lh = (lh == 0) ? 1 : 2;
		else if (s[i] == 'h' && (lh == 0 || lh == 3))
			lh = (lh == 0) ? 3 : 4;
	}
	return (ft_dioux_llhh(lh, c, ap, m));
}
