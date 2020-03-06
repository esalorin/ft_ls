/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:47:54 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/17 15:22:40 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_sort_time(t_files *first, int r)
{
	t_files	*check;
	t_files	*temp;
	int		swap;

	swap = 0;
	temp = first->next;
	check = temp->next;
	while (temp->next != NULL)
	{
		if ((r == 0 && temp->seconds < check->seconds) ||
			(r == 1 && temp->seconds > check->seconds))
		{
			ft_swap(&check->seconds, &temp->seconds);
			ft_strswap(&check->name, &temp->name);
			ft_strswap(&check->path, &temp->path);
			swap++;
		}
		check = check->next;
		temp = temp->next;
	}
	if (swap != 0)
		ft_sort_time(first, r);
}

void	ft_sort_names(t_files *first, int r)
{
	t_files	*check;
	t_files	*temp;
	int		swap;

	swap = 0;
	temp = first->next;
	check = temp->next;
	while (temp->next != NULL)
	{
		if ((ft_strcmp(temp->name, check->name) > 0 && temp->name[0] != '.'
		&& r == 0) || (r == 1 && ft_strcmp(temp->name, check->name) < 0))
		{
			ft_strswap(&check->name, &temp->name);
			ft_swap(&check->seconds, &temp->seconds);
			ft_strswap(&check->path, &temp->path);
			swap++;
		}
		check = check->next;
		temp = temp->next;
	}
	if (swap != 0)
		ft_sort_names(first, r);
}

void	ft_sort(t_ls *ls, char *sub)
{
	ft_flags(ls, sub);
	ft_get_path(ls);
	ft_seconds(ls);
	ft_sort_names(ls->first, ls->r);
	if (ls->t == 1)
		ft_sort_time(ls->first, ls->r);
	ft_get_info(ls);
	if (ls->first->next->permissions)
	{
		ft_printing(ls);
		if (ls->rec == 1)
			ft_recursive(ls, sub);
	}
}
