/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:30:12 by esalorin          #+#    #+#             */
/*   Updated: 2020/01/10 13:33:34 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	long	nbr;
	long	temp;
	int		i;
	char	*s;

	i = (n < 0) ? 2 : 1;
	nbr = (n < 0) ? -n : n;
	temp = nbr;
	while ((temp = temp / 10) > 0)
		i++;
	if (!(s = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	s[i--] = '\0';
	if (nbr == 0)
		s[0] = '0';
	while (nbr > 0)
	{
		s[i--] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
