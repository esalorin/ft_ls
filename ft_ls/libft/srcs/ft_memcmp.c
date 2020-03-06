/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:16:13 by esalorin          #+#    #+#             */
/*   Updated: 2019/11/02 13:38:55 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s;
	unsigned char *p;

	s = (unsigned char*)s1;
	p = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (n-- > 1)
	{
		if (*s != *p)
			break ;
		s++;
		p++;
	}
	return (*s - *p);
}
