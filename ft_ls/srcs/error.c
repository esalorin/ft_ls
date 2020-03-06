/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:43:36 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/17 15:10:39 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_error(char *s)
{
	char	*r;

	r = ft_strjoin("ft_ls: ", s);
	perror(r);
	ft_memdel((void**)&r);
}

char	*ft_illegal(char c)
{
	char	*des;
	char	*temp;
	char	*temp2;

	temp = ft_strnew(1);
	temp[0] = c;
	temp2 = ft_strjoin(temp, "\nusage: ft_ls [-Ralrt] [file ...]\n");
	free(temp);
	des = ft_strjoin("ft_ls: illegal option -- ", temp2);
	free(temp2);
	return (des);
}
