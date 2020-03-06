/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:13:33 by esalorin          #+#    #+#             */
/*   Updated: 2019/10/29 14:18:16 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int a;

	i = 0;
	a = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			a = i;
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	if (a == -1)
		return (NULL);
	return ((char *)s + a);
}
