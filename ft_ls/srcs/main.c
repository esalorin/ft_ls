/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:31:34 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/17 15:46:31 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_check_illegal(char *s)
{
	char	*valid;
	char	*temp;
	int		i;

	valid = "Ralrt";
	if ((s[1] == '-' && ft_strlen(s) == 2))
		return ;
	s++;
	while (*s)
	{
		i = 0;
		while (valid[i])
		{
			if (*s == valid[i])
				break ;
			i++;
		}
		if (!valid[i])
		{
			temp = ft_illegal(*s);
			ft_putstr_fd(temp, 2);
			exit(1);
		}
		s++;
	}
}

static char	*ft_more_flags(char **av, int *i)
{
	int		a;
	char	*s;
	char	*s2;

	a = *i;
	s = NULL;
	while (av[a] && av[a][0] == '-')
	{
		if (ft_strlen(av[a]) == 1)
			break ;
		ft_check_illegal(av[a]);
		if (a == 1 && av[a + 1] && av[a + 1][0] == '-')
			s = ft_strjoin(av[a], av[a + 1]);
		else if (av[a + 1] && av[a + 1][0] == '-')
		{
			s2 = ft_strjoin(s, av[a + 1]);
			free(s);
			s = s2;
		}
		a++;
		(*i)++;
	}
	if (!av[a])
		*i = 0;
	return ((s == NULL) ? av[1] : s);
}

int			main(int ac, char **av)
{
	int		i;
	int		ret;
	char	*sub;

	i = 1;
	ret = 0;
	sub = NULL;
	if (ac == 1)
		ret = ft_read_dir(".", NULL);
	else if (i == 1 && av[i][0] == '-')
		sub = ft_more_flags(av, &i);
	if ((ac == 2 || i == 0) && av[1][0] == '-' && ft_strlen(av[1]) != 1)
		ret = ft_read_dir(".", sub);
	else if (ac > 1)
		ft_check_params(av, sub, i, 1);
	if (ret == -1)
		ft_error(av[i]);
	return (0);
}
