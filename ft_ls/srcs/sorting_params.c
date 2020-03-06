/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:38:27 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/17 14:23:28 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_dir_time(t_dirs *d, int r)
{
	int		swap;
	t_dirs	*temp;
	t_dirs	*temp2;

	swap = 0;
	temp = d;
	temp2 = d->next;
	while (temp2 != NULL)
	{
		if ((r == 0 && temp->sec < temp2->sec) || (r == 1 &&
		temp->sec > temp2->sec))
		{
			ft_strswap(&temp->dir, &temp2->dir);
			ft_swap(&temp->sec, &temp2->sec);
			swap++;
		}
		temp = temp2;
		temp2 = temp2->next;
	}
	if (swap != 0)
		ft_dir_time(d, r);
}

static void	ft_dir_names(t_dirs *d, int r)
{
	int		swap;
	t_dirs	*temp;
	t_dirs	*temp2;

	swap = 0;
	temp = d;
	temp2 = d->next;
	while (temp->next != NULL)
	{
		if ((r == 0 && ft_strcmp(temp->dir, temp2->dir) > 0) ||
		(r == 1 && ft_strcmp(temp->dir, temp2->dir) < 0))
		{
			ft_strswap(&temp->dir, &temp2->dir);
			ft_swap(&temp->sec, &temp2->sec);
			swap++;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	if (swap != 0)
		ft_dir_names(d, r);
}

void		ft_sort_dirs(t_dirs *head, char *flags, int params)
{
	t_dirs	*d;
	int		r;
	int		ret;

	d = head->next;
	r = (flags && ft_strchr(flags, 'r')) ? 1 : 0;
	if (d != NULL)
		ft_dir_names(d, r);
	if (flags && ft_strchr(flags, 't') && d != NULL)
		ft_dir_time(d, r);
	while (d != NULL)
	{
		if (params > 1)
			ft_printf("%s:\n", d->dir);
		if (d && (!flags || (flags[0] != '-' || ft_strlen(flags) == 1)))
			ret = ft_read_dir(d->dir, NULL);
		else if (d && flags && flags[0] == '-')
			ret = ft_read_dir(d->dir, flags);
		if (ret == -1)
			ft_error(d->dir);
		d = d->next;
		if (params > 1 && d != NULL)
			ft_putchar('\n');
	}
}

void		ft_file_sorting(t_ls *ls, char *flags)
{
	t_files *l;

	l = ls->first->next;
	while (l != NULL)
	{
		l->path = ft_strdup(l->name);
		l = l->next;
	}
	ls->dir = NULL;
	ft_flags(ls, flags);
	ft_get_info(ls);
	ft_seconds(ls);
	if (ls->first->next != NULL)
		ft_sort_names(ls->first, ls->r);
	if (ls->t == 1 && ls->first->next != NULL)
		ft_sort_time(ls->first, ls->r);
	ft_printing(ls);
}

void		ft_no_such(char **dir)
{
	int	i;
	int	swap;

	swap = 0;
	i = 0;
	while (dir[i] && dir[i + 1])
	{
		if (ft_strcmp(dir[i], dir[i + 1]) > 0)
		{
			ft_strswap(&dir[i], &dir[i + 1]);
			swap++;
		}
		i++;
	}
	if (swap != 0)
		ft_no_such(dir);
}
