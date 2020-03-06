/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:01:15 by esalorin          #+#    #+#             */
/*   Updated: 2019/10/29 14:09:52 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
		new[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}
