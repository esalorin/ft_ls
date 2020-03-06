/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ids.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:53:43 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/07 14:46:46 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*ft_user(uid_t st_uid)
{
	struct passwd *p;

	if (!(p = getpwuid(st_uid)))
	{
		if (p == 0)
			return (ft_itoa(st_uid));
		else
			return (NULL);
	}
	return (ft_strdup(p->pw_name));
}

char	*ft_group(gid_t st_gid)
{
	struct group *g;

	if (!(g = getgrgid(st_gid)))
	{
		if (g == 0)
			return (ft_itoa(st_gid));
		else
			return (NULL);
	}
	return (ft_strdup(g->gr_name));
}
