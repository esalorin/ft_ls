/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:59:14 by esalorin          #+#    #+#             */
/*   Updated: 2019/10/29 20:00:16 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		while (haystack[i + a] == needle[a])
		{
			a++;
			if (needle[a] == '\0')
				return ((char*)haystack + i);
		}
		a = 0;
		i++;
	}
	return (NULL);
}
