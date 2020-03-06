/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:47:46 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/17 15:12:01 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_print_file(t_ls *ls, t_files *l, unsigned int col)
{
	int	len;

	if (l->type == 'l')
		ft_parse_link(l->name);
	len = ft_strlen(l->name);
	ft_printf("%s", l->name);
	while (col != 1 && l->next != NULL && len++ <= ls->max_len)
		write(1, " ", 1);
}

static void	ft_only_wfiles(t_ls *ls, unsigned int col)
{
	int				c;
	t_files			*l;

	l = ls->first->next;
	while (l != NULL)
	{
		c = (ls->count % col == 0) ? ls->count / col : (ls->count / col) + 1;
		while (l && (l->printed == 1 || (ls->a == 0 && l->name[0] == '.')))
			l = l->next;
		if (l)
		{
			l->printed = 1;
			ft_print_file(ls, l, col);
		}
		while (l && c != 0)
		{
			if ((l = l->next) == NULL)
			{
				ft_putchar('\n');
				l = ls->first->next;
				break ;
			}
			c -= (ls->a == 1 || (ls->a == 0 && l->name[0] != '.')) ? 1 : 0;
		}
	}
}

static void	ft_only_files(t_ls *ls)
{
	t_files	*l;
	int		printed;
	int		len;

	printed = 0;
	l = ls->first->next;
	while (l != NULL)
	{
		if (ls->a == 1 || (ls->a == 0 && l->name[0] != '.'))
		{
			printed++;
			if (l->type == 'l')
				ft_parse_link(l->name);
			len = ft_strlen(l->name);
			ft_printf("%s", l->name);
			while (l->next != NULL && len++ <= ls->max_len)
				write(1, " ", 1);
		}
		l = l->next;
	}
	if (printed)
		ft_putchar('\n');
}

static void	ft_print_long(t_ls *ls)
{
	t_files *l;

	l = ls->first->next;
	if (ft_if_total(ls))
		ft_printf("total %d\n", ls->total);
	while (l != NULL && l->permissions != NULL)
	{
		if ((ls->a == 0 && l->name[0] != '.') || ls->a == 1)
		{
			ft_printf("%c%s  ", l->type, l->permissions);
			ft_check_width(ls->width_links, ft_nbrlen(l->links));
			ft_printf("%d ", l->links);
			ft_check_width(ls->width_user, ft_strlen(l->user));
			ft_printf("%s  ", l->user);
			ft_check_width(ls->width_group, ft_strlen(l->group));
			ft_printf("%s  ", l->group);
			ft_check_width(ls->width_size, ft_nbrlen(l->size));
			ft_printf("%d %s %s\n", l->size, l->date, l->name);
		}
		l = l->next;
	}
}

void		ft_printing(t_ls *ls)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (ls->l == 1)
		ft_print_long(ls);
	else if ((ls->a == 0 && (w.ws_col / ls->max_len) > ls->count) ||
	(ls->a == 1 && (w.ws_col / ls->max_len) > ls->acount))
		ft_only_files(ls);
	else
	{
		ls->count = (ls->a == 1) ? ls->acount : ls->count;
		if (w.ws_col / ls->max_len == 0)
			ft_only_wfiles(ls, 1);
		else
		{
			ft_only_wfiles(ls, (w.ws_col / ls->max_len));
		}
	}
}
