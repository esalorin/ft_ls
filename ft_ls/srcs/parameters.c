/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:40:58 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/02/17 14:21:41 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_add_dir(t_dirs *d, char *name)
{
	t_dirs		*temp;
	struct stat	buf;

	if (d == NULL)
	{
		temp = (t_dirs*)malloc(sizeof(t_dirs));
		temp->dir = ft_strdup(name);
		lstat(name, &buf);
		temp->sec = buf.st_mtime;
		temp->next = NULL;
		d = temp;
	}
	else
	{
		temp = d;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = (t_dirs*)malloc(sizeof(t_dirs));
		temp = temp->next;
		temp->dir = ft_strdup(name);
		lstat(name, &buf);
		temp->sec = buf.st_mtime;
		temp->next = NULL;
	}
}

static void	ft_dir_params(char **dir, char *flags, int print, int params)
{
	int			i;
	t_dirs		*head;

	i = 0;
	head = (t_dirs*)malloc(sizeof(t_dirs));
	head->next = NULL;
	while (dir[i])
	{
		ft_add_dir(head, dir[i]);
		i++;
	}
	if (print != 0 && i != 0)
		ft_putchar('\n');
	ft_sort_dirs(head, flags, params);
	ft_del_dirs(head);
}

static int	ft_file_params(char **dir, char *flags)
{
	int		i;
	t_ls	*ls;

	i = 0;
	ls = (t_ls*)malloc(sizeof(t_ls));
	ls->max_len = 0;
	ls->count = 0;
	ls->acount = 0;
	ls->first = (t_files*)malloc(sizeof(t_files));
	ls->first->next = NULL;
	while (dir && dir[i])
	{
		ft_add_elem(ls->first, dir[i]);
		if ((int)ft_strlen(dir[i]) > ls->max_len)
			ls->max_len = ft_strlen(dir[i]);
		ls->count++;
		i++;
	}
	ls->acount = ls->count;
	ft_file_sorting(ls, flags);
	ft_del_files(ls);
	return (i);
}

static void	ft_sort_params(char **dir, char *flags, int count, int params)
{
	static int	print;
	int			i;
	char		*er;

	i = 0;
	if (dir[0] && count == 1)
	{
		ft_no_such(dir);
		while (dir[i])
		{
			ft_if_dir(dir[i]);
			er = ft_strjoin("ft_ls: ", dir[i++]);
			perror(er);
			ft_memdel((void**)&er);
		}
	}
	else if (dir[0] && count == 2)
		print = ft_file_params(dir, flags);
	else if (dir[0] && count == 3)
		ft_dir_params(dir, flags, print, params);
}

int			ft_check_params(char **av, char *flags, int i, int count)
{
	int		j;
	int		a;
	char	**dir;

	j = i;
	a = 0;
	while (av[j])
		j++;
	dir = (char**)malloc(sizeof(char*) * (j - i + 2));
	j = i - 1;
	while (av[++j])
	{
		if (ft_if_dir(av[j]) == 0 && count == 1)
			dir[a++] = ft_strdup(av[j]);
		else if (ft_if_dir(av[j]) == 1 && count == 2)
			dir[a++] = ft_strdup(av[j]);
		else if (ft_if_dir(av[j]) == 2 && count == 3)
			dir[a++] = ft_strdup(av[j]);
	}
	dir[a] = 0;
	ft_sort_params(dir, flags, count, j - i);
	if (count < 3)
		ft_check_params(av, flags, i, count + 1);
	ft_del_array(dir);
	return (1);
}
