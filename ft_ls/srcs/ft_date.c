/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:58:48 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/03 18:13:36 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_seconds(t_ls *ls)
{
	t_files		*list;
	struct stat	buf;

	list = ls->first->next;
	while (list != NULL && lstat(list->path, &buf) != -1)
	{
		if (ft_type(ft_itoa_base(buf.st_mode, 8, 0)) == 'l')
			ft_link(list, 20);
		list->seconds = buf.st_mtime;
		list = list->next;
	}
}

char	*ft_date(time_t st_time)
{
	time_t	sec;
	char	*t;
	char	*s1;
	char	*s2;
	char	*dest;

	t = ctime(&st_time);
	sec = time(&sec);
	s1 = ft_strsub(t, 4, 7);
	if (st_time > (sec + 15778463) || st_time < (sec - 15778463))
		s2 = ft_strsub(t, 19, 5);
	else
		s2 = ft_strsub(t, 11, 5);
	dest = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (dest);
}
