/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:20:09 by esalorin          #+#    #+#             */
/*   Updated: 2019/10/29 15:09:22 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n)
	{
		if (*(unsigned char*)src == (unsigned char)c)
		{
			*(unsigned char*)dst++ = (unsigned char)c;
			return (dst);
		}
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		n--;
	}
	return (NULL);
}
