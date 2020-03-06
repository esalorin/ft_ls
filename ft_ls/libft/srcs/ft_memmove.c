/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:16:27 by esalorin          #+#    #+#             */
/*   Updated: 2019/10/29 15:05:13 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src1;
	unsigned char	*dst1;

	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	if (src1 == dst1)
		return (dst);
	if (src1 < dst1)
	{
		while (len--)
			dst1[len] = src1[len];
	}
	else
		while (len--)
			*dst1++ = *src1++;
	return (dst);
}
