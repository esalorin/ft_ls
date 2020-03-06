/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:45:09 by esalorin          #+#    #+#             */
/*   Updated: 2020/01/22 17:18:29 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_first(char *res, long long value, int base)
{
	if (value == 0)
		res[0] = '0';
	else if (value < 0 && base == 10)
		res[0] = '-';
	return (res);
}

char	*ft_itoa_base(long long value, int base, char c)
{
	char				*str;
	char				*res;
	int					i;
	unsigned long long	temp;
	unsigned long long	n;

	if (c >= 'A' && c <= 'Z')
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	i = 1;
	if (value < 0)
		i = (base == 10) ? 2 : 1;
	n = (value < 0) ? -value : value;
	temp = n;
	while ((temp = temp / base) > 0)
		i++;
	res = ft_strnew(i);
	while (n > 0)
	{
		res[--i] = str[n % base];
		n = n / base;
	}
	return (ft_first(res, value, base));
}
