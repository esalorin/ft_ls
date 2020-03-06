/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:19:35 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/01/18 17:51:34 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_unsigned(unsigned long long value, int base, char c)
{
	char				*res;
	char				*str;
	int					i;
	unsigned long long	temp;

	i = 1;
	if (c >= 'a' && c <= 'z')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	temp = value;
	while ((temp = temp / base) > 0)
		i++;
	res = ft_strnew(i);
	if (value == 0)
		res[0] = '0';
	while (value > 0)
	{
		res[--i] = str[value % base];
		value = value / base;
	}
	return (res);
}
