/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:38:06 by esalorin          #+#    #+#             */
/*   Updated: 2019/10/29 14:19:06 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (NULL);
	while (i < len)
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}
