/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:33:22 by esalorin          #+#    #+#             */
/*   Updated: 2020/01/27 16:09:16 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip(const char *f)
{
	int	a;

	a = 1;
	while (*f != '\0' && (*f != 'd' && *f != 'i' && *f != 'o' && *f != 'u'
		&& *f != 'x' && *f != 'X' && *f != 'f' && *f != 'c' && *f != 's'
		&& *f != 'p' && *f != '%'))
	{
		a++;
		f++;
	}
	if (*f == '\0')
		a--;
	return (a);
}

static int	ft_type(const char *f, int i, va_list ap)
{
	int		l;
	char	*sub;

	l = 0;
	if (f[i] == 'c' || f[i] == 's' || f[i] == 'p')
		l = ft_print_csp(f[i], ap, &l, 0);
	else if (f[i] == 'd' || f[i] == 'i' || f[i] == 'o' || f[i] == 'u' ||
		f[i] == 'x' || f[i] == 'X')
		l = ft_print_dioux(f[i], ap, 0, &l);
	else if (f[i] == 'f')
		l = ft_print_double(ap, 6, 0, &l);
	else
	{
		l = i;
		while (f[l] != 'd' && f[l] != 'i' && f[l] != 'o' && f[l] != 'u' && f[l]
		!= '%' && f[l] != 'x' && f[l] != 'X' && f[l] != 'f' && f[l] != 'c' &&
		f[l] != 's' && f[l] != 'p' && f[l] != '\0')
			l++;
		if (f[l] == '\0')
			return (0);
		sub = ft_strsub(f, i, (l - i + 1));
		l = ft_print_flags(sub, ap);
		free(sub);
	}
	return (l);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		i;
	int		ret;
	int		skip;
	int		temp;

	skip = 0;
	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			temp = (format[++i]) ? ft_skip(&format[i]) : 0;
			ret = ret + ft_type(format, i, ap);
			i = i + temp;
			skip = skip + 1 + temp;
		}
		else if (format[i])
			ft_putchar(format[i++]);
	}
	va_end(ap);
	return (((ret + i) - skip));
}
