/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dioux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:46:16 by esalorin          #+#    #+#             */
/*   Updated: 2020/01/27 16:09:30 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_dioux(char *s, int *m)
{
	int res;
	int	i;

	i = 0;
	res = ft_strlen(s);
	if (m[3] == 1)
		ft_putstr(s);
	if (m[1] == 1 && m[3] == -1 && m[6] == -1)
	{
		if (s[i] == ' ' || s[i] == '+' || s[i] == '-' || s[1] == 'x' || s[1]
		== 'X')
			ft_putchar(s[i++]);
		(s[1] == 'x' || s[1] == 'X') ? ft_putchar(s[i++]) : 1;
		while (m[5] > res++)
			write(1, "0", 1);
	}
	if (m[1] == -1 || m[3] == 1 || m[6] > 0)
	{
		while (m[5] > res++)
			write(1, " ", 1);
	}
	if (m[3] == -1)
		ft_putstr(&s[i]);
	free(s);
	return (res - 1);
}

static char	*ft_maketemp(int n, int i)
{
	char	*s;
	int		len;

	len = n + i;
	s = ft_strnew(len);
	while (len-- > i)
		s[len] = '0';
	if (i == 1)
		s[0] = '-';
	return (s);
}

int			ft_check_oux(char *s, char c, int *m)
{
	char	*s1;
	char	*s2;
	char	*temp;
	int		len;

	s1 = NULL;
	s2 = NULL;
	if (m[6] == 0 && s[0] == '0')
		s[0] = '\0';
	if (m[0] == 1 && c == 'o' && s[0] != '0')
		s1 = ft_strjoin("0", s);
	s1 = (s1 == NULL) ? ft_strdup(s) : s1;
	if (m[6] > (len = ft_strlen(s1)))
	{
		temp = ft_maketemp(m[6] - len, 0);
		s2 = ft_strjoin(temp, s1);
		ft_strdel(&temp);
	}
	s2 = (s2 == NULL) ? ft_strdup(s1) : s2;
	if (m[0] == 1 && (c == 'x' || c == 'X') && s1[0] != '0' && s1[0] != '\0')
		temp = ft_strjoin(((c == 'x') ? "0x" : "0X"), s2);
	temp = (temp == NULL) ? ft_strdup(s2) : temp;
	free(s1);
	free(s2);
	return (ft_check_dioux(temp, m));
}

int			ft_check_di(char *s, int *m)
{
	char	*s1;
	char	*temp;
	int		len;
	int		i;

	s1 = NULL;
	if (m[6] == 0 && s[0] == '0')
		s[0] = '\0';
	i = (s[0] == '-') ? 1 : 0;
	if (m[6] > (len = ft_strlen(&s[i])))
	{
		temp = ft_maketemp(m[6] - len, i);
		s1 = ft_strjoin(temp, &s[i]);
		free(temp);
	}
	temp = NULL;
	s1 = (s1 == NULL) ? ft_strdup(s) : s1;
	if (m[2] == 1 && s[0] != '-')
		temp = ft_strjoin("+", s1);
	if (m[4] == 1 && m[2] == -1 && s[0] != '-')
		temp = ft_strjoin(" ", s1);
	temp = (temp == NULL) ? ft_strdup(s1) : temp;
	free(s1);
	return (ft_check_dioux(temp, m));
}
