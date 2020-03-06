/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:38:35 by esalorin          #+#    #+#             */
/*   Updated: 2019/11/01 18:13:44 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		a;
	int		len;
	char	*str;

	i = 0;
	a = 0;
	len = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	len++;
	if (s[i] == '\0')
		len = i;
	str = (char *)malloc(sizeof(char) * (len - i + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
		str[a++] = s[i++];
	str[a] = '\0';
	return (str);
}
