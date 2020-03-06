/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:49:10 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/10 16:39:28 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static t_files	*ft_create_next(char *name)
{
	t_files	*new;

	new = (t_files*)malloc(sizeof(t_files));
	new->name = ft_strdup(name);
	new->printed = 0;
	new->next = NULL;
	return (new);
}

void			ft_add_elem(t_files *first, char *name)
{
	t_files			*temp;

	if (first->next == NULL)
	{
		temp = ft_create_next(name);
		first->next = temp;
	}
	else
	{
		temp = first;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = ft_create_next(name);
	}
}

int				ft_read_dir(char *file, char *sub)
{
	t_ls			*ls;
	DIR				*dirp;
	struct dirent	*dp;

	ls = (t_ls*)malloc(sizeof(t_ls));
	ls->dir = ft_strdup(file);
	ls->max_len = 0;
	ls->count = 0;
	ls->acount = 0;
	ls->first = (t_files*)malloc(sizeof(t_files));
	ls->first->next = NULL;
	if (!(dirp = opendir(ls->dir)))
		return (-1);
	while ((dp = readdir(dirp)))
	{
		ft_add_elem(ls->first, dp->d_name);
		if ((int)ft_strlen(dp->d_name) > ls->max_len)
			ls->max_len = (int)ft_strlen(dp->d_name);
		ls->count += (dp->d_name[0] == '.') ? 0 : 1;
		ls->acount++;
	}
	ft_sort(ls, sub);
	if (closedir(dirp) == -1)
		return (-1);
	return (ft_delete(ls));
}
