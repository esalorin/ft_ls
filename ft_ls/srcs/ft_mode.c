/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:31:15 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/17 15:23:20 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char		ft_type(char *type)
{
	char	c;

	if (ft_strlen(type) == 5)
	{
		if (type[0] == '4')
			c = 'd';
		else if (type[0] == '2')
			c = 'c';
		else if (type[0] == '6')
			c = 'b';
		else
			c = 'p';
	}
	else
	{
		if (type[1] == '0')
			c = '-';
		else if (type[1] == '2')
			c = 'l';
		else
			c = 's';
	}
	free(type);
	return (c);
}

static char	*ft_special_perm(char *s, char m)
{
	if (m == '4' || m == '5' || m == '6' || m == '7')
		s[2] = (s[2] == '-') ? 'S' : 's';
	if (m == '2' || m == '3' || m == '6' || m == '7')
		s[5] = (s[5] == '-') ? 'S' : 's';
	if (m == '1' || m == '3' || m == '5' || m == '7')
		s[8] = (s[8] == '-') ? 'T' : 't';
	return (s);
}

char		*ft_mode(char *m)
{
	char	*mode;
	int		len;

	mode = ft_strnew(9);
	len = ft_strlen(m) - 4;
	while (m[++len] != '\0')
	{
		if (m[len] == '0')
			mode = ft_strcat(mode, "---");
		else if (m[len] == '1')
			mode = ft_strcat(mode, "--x");
		else if (m[len] == '2')
			mode = ft_strcat(mode, "-w-");
		else if (m[len] == '3')
			mode = ft_strcat(mode, "-wx");
		else if (m[len] == '4')
			mode = ft_strcat(mode, "r--");
		else if (m[len] == '5')
			mode = ft_strcat(mode, "r-x");
		else if (m[len] == '6')
			mode = ft_strcat(mode, "rw-");
		else
			mode = ft_strcat(mode, "rwx");
	}
	return (ft_special_perm(mode, m[len - 4]));
}
