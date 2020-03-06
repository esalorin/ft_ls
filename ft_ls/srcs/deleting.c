/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:16:42 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/17 15:11:02 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_del_array(char **dir)
{
	int i;

	i = 0;
	while (dir[i])
		ft_memdel((void**)&dir[i++]);
	free(dir);
}

void	ft_del_files(t_ls *ls)
{
	t_files *f;
	t_files	*temp;

	f = ls->first->next;
	while (f != NULL)
	{
		temp = f;
		ft_memdel((void**)&f->permissions);
		ft_memdel((void**)&f->user);
		ft_memdel((void**)&f->name);
		ft_memdel((void**)&f->group);
		ft_memdel((void**)&f->date);
		ft_memdel((void**)&f->path);
		f = f->next;
		ft_memdel((void**)&temp);
	}
	ft_memdel((void**)&ls->first);
	ft_memdel((void**)&ls);
}

void	ft_del_dirs(t_dirs *d)
{
	t_dirs *temp;
	t_dirs *temp2;

	temp = d->next;
	while (temp != NULL)
	{
		ft_memdel((void**)&temp->dir);
		temp2 = temp;
		temp = temp->next;
		ft_memdel((void**)&temp2);
	}
	ft_memdel((void**)&d);
}

int		ft_delete(t_ls *ls)
{
	t_files *f;
	t_files	*temp;

	f = ls->first->next;
	while (f != NULL && f->permissions)
	{
		temp = f;
		ft_memdel((void**)&f->permissions);
		ft_memdel((void**)&f->user);
		ft_memdel((void**)&f->name);
		ft_memdel((void**)&f->group);
		ft_memdel((void**)&f->date);
		ft_memdel((void**)&f->path);
		f = f->next;
		ft_memdel((void**)&temp);
	}
	ft_memdel((void**)&ls->first);
	ft_memdel((void**)&ls->dir);
	ft_memdel((void**)&ls);
	return (1);
}
