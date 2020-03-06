/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:51:55 by esalorin          #+#    #+#             */
/*   Updated: 2019/11/02 14:02:35 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t a;

	i = 0;
	a = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[a])
		{
			i++;
			a++;
			if (needle[a] == '\0')
				return ((char *)haystack + i - a);
		}
		else
		{
			i++;
			a = 0;
		}
	}
	return (NULL);
}
