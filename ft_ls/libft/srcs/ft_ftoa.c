/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:18:38 by esalorin          #+#    #+#             */
/*   Updated: 2020/01/23 15:47:08 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_freenjoin(char *s1, char *s2)
{
	char *des;

	des = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (des);
}

static char	*ft_before(long double n, int f)
{
	long	temp;
	long	n2;
	int		i;
	char	*s1;

	i = (n < 0) ? 2 : 1;
	temp = (n < 0) ? -n : n;
	if (f == -1)
		temp = temp + 1;
	n2 = temp;
	while ((temp = temp / 10) > 0)
		i++;
	if (!(s1 = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s1[i] = '\0';
	while (i-- > 0)
	{
		s1[i] = (n2 % 10) + 48;
		n2 = n2 / 10;
	}
	if (n < 0)
		s1[0] = '-';
	return (s1);
}

static char	*ft_precision(char *s, int p, int *f)
{
	char	*des;
	int		i;

	i = ft_strlen(s);
	if (!(des = ft_strnew(i)))
		return (NULL);
	des = ft_strncpy(des, s, (i - 1));
	i--;
	if (s[i] >= '5' && s[i] <= '9')
	{
		while (des[--i] == '9')
			des[i] = '0';
		if (des[i] == '.')
			*f = -1;
		else
			des[i] = des[i] + 1;
	}
	if (p == 0)
		des[0] = '\0';
	return (des);
}

static char	*ft_after(char *s2, long double n, int p)
{
	long		temp;
	int			i;
	int			p2;
	char		*s1;
	long double	n2;

	n2 = n;
	i = 0;
	p2 = p;
	temp = n;
	n = (n - temp) * 10;
	n = (n < 0) ? -n : n;
	s2[i++] = '.';
	while (n != 0 && (p-- + 1) > 0)
	{
		temp = n;
		s2[i++] = temp + 48;
		n = (n - temp) * 10;
	}
	while ((p-- + 1) > 0)
		s2[i++] = '0';
	s1 = ft_precision(s2, p2, &i);
	return (ft_freenjoin(ft_before(n2, i), s1));
}

char		*ft_ftoa(long double n, int p)
{
	int		i;
	char	*s;
	char	*s2;

	if (!(s2 = ft_strnew(p + 2)))
		return (NULL);
	if (n == 0)
	{
		if (p == 0)
			s = "0";
		else
		{
			i = 0;
			while (p-- > 0)
				s2[i++] = '0';
			s2[i] = '\0';
			s = ft_strjoin("0.", s2);
		}
	}
	else
	{
		s = ft_after(s2, n, p);
	}
	free(s2);
	return (s);
}
