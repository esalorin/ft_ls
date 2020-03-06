/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:35:20 by esalorin          #+#    #+#             */
/*   Updated: 2020/01/27 16:07:02 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base(char c, unsigned int base)
{
	unsigned int	i;
	char			*s1;
	char			*s2;

	s1 = "0123456789abcdef";
	s2 = "0123456789ABCDEF";
	i = 0;
	while (i < base && c != s1[i] && c != s2[i])
		i++;
	if (i == base)
		return (-1);
	return (i);
}

long long	ft_atoi_base(const char *nbr, unsigned int base)
{
	int			sign;
	long long	res;
	long long	n;
	int			i;

	sign = 1;
	res = 0;
	i = 0;
	while (nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\n' || nbr[i] == '\f'
			|| nbr[i] == '\v' || nbr[i] == '\r')
		i++;
	if (i == 0 && nbr[i] == '-')
		sign = -1;
	(sign == -1) ? i++ : i;
	while ((n = ft_base(nbr[i++], base)) >= 0)
		res = res * base + n;
	return (res * sign);
}
