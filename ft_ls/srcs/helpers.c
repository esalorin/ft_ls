/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:51:24 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/17 15:07:01 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		ft_if_dir(char *file)
{
	DIR			*dp;
	struct stat	buf;

	if ((dp = opendir(file)))
	{
		closedir(dp);
		return (2);
	}
	else if (lstat(file, &buf) != -1)
	{
		if (ft_type(ft_itoa_base(buf.st_mode, 8, 0)) == 'd')
			return (2);
		else
			return (1);
	}
	return (0);
}

void	ft_check_width(int width, int nbr)
{
	while (nbr++ < width)
		write(1, " ", 1);
}

void	ft_width(int len, int *width)
{
	if (len > *width)
		*width = len;
}

void	ft_parse_link(char *name)
{
	int		i;

	i = 0;
	while (name[i] && name[i] != ' ')
		i++;
	bzero(&name[i], (ft_strlen(name) - i));
}

int		ft_if_total(t_ls *ls)
{
	t_files *file;

	file = ls->first->next;
	while (ls->dir && file != NULL)
	{
		if (ls->a == 1)
			return (1);
		else if (ls->a == 0 && file->name[0] != '.')
			return (1);
		file = file->next;
	}
	return (0);
}
