/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:40:54 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/17 15:09:31 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		ft_recursive(t_ls *ls, char *sub)
{
	t_files *l;

	l = ls->first->next;
	while (l != NULL)
	{
		if ((ls->a == 1 || (ls->a == 0 && l->name[0] != '.')) &&
		l->type == 'd' && ft_strcmp(l->name, ".") && ft_strcmp(l->name, ".."))
		{
			ft_printf("\n%s:\n", l->path);
			if (ft_read_dir(l->path, sub) == -1)
				ft_error(l->name);
		}
		l = l->next;
	}
}

void		ft_get_path(t_ls *ls)
{
	t_files	*list;
	char	*temp;

	list = ls->first->next;
	while (list != NULL)
	{
		temp = ft_strjoin(ls->dir, "/");
		list->path = ft_strjoin(temp, list->name);
		free(temp);
		list = list->next;
	}
}

void		ft_link(t_files *list, size_t bufsize)
{
	char	*buf;
	char	*temp;
	size_t	size;

	buf = ft_strnew(bufsize);
	size = readlink(list->path, buf, bufsize);
	if (size < bufsize)
	{
		temp = ft_strjoin(list->name, " -> ");
		free(list->name);
		list->name = ft_strjoin(temp, buf);
		free(buf);
		free(temp);
		return ;
	}
	free(buf);
	ft_link(list, (2 * size));
}

void		ft_get_info(t_ls *ls)
{
	t_files		*list;
	struct stat	buf;
	char		*mode;

	ls->total = 0;
	list = ls->first->next;
	(list != NULL) ? list->permissions = NULL : 0;
	while (list != NULL && lstat(list->path, &buf) != -1)
	{
		if (ls->a == 1 || (ls->a == 0 && list->name[0] != '.'))
			ls->total = ls->total + buf.st_blocks;
		mode = ft_itoa_base(buf.st_mode, 8, 0);
		list->permissions = ft_mode(mode);
		list->type = ft_type(mode);
		list->links = buf.st_nlink;
		ft_width(ft_nbrlen(list->links), &ls->width_links);
		list->user = ft_user(buf.st_uid);
		ft_width(ft_strlen(list->user), &ls->width_user);
		list->group = ft_group(buf.st_gid);
		ft_width(ft_strlen(list->group), &ls->width_group);
		list->size = buf.st_size;
		ft_width(ft_nbrlen(list->size), &ls->width_size);
		list->date = ft_date(buf.st_mtime);
		list = list->next;
	}
}

void		ft_flags(t_ls *ls, char *sub)
{
	ls->l = 0;
	ls->a = 0;
	ls->r = 0;
	ls->t = 0;
	ls->rec = 0;
	ls->width_size = 0;
	ls->width_links = 0;
	ls->width_user = 0;
	ls->width_group = 0;
	if (sub && *sub == '-')
	{
		if (ft_strchr(sub, 'l'))
			ls->l = 1;
		if (ft_strchr(sub, 'a'))
			ls->a = 1;
		if (ft_strchr(sub, 'r'))
			ls->r = 1;
		if (ft_strchr(sub, 't'))
			ls->t = 1;
		if (ft_strchr(sub, 'R'))
			ls->rec = 1;
	}
}
