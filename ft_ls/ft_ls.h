/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:49:53 by esalorin          #+#    #+#             */
/*   Updated: 2020/02/17 14:18:07 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/srcs/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>

typedef struct		s_dirs
{
	char			*dir;
	long long		sec;
	struct s_dirs	*next;
}					t_dirs;

typedef struct		s_files
{
	char			*permissions;
	char			type;
	char			*name;
	char			*user;
	char			*group;
	char			*date;
	char			*path;
	long long		seconds;
	int				size;
	int				links;
	int				printed;
	struct s_files	*next;
}					t_files;

typedef struct		s_ls
{
	char			*dir;
	int				l;
	int				a;
	int				r;
	int				t;
	int				rec;
	int				count;
	int				acount;
	int				total;
	int				max_len;
	int				width_group;
	int				width_user;
	int				width_size;
	int				width_links;
	t_files			*first;
}					t_ls;

char				*ft_user(uid_t st_uid);
char				*ft_group(gid_t st_gid);
char				*ft_mode(char *m);
char				*ft_date(time_t st_time);
char				*ft_illegal(char c);

char				ft_type(char *type);

void				ft_sort(t_ls *ls, char *sub);
void				ft_flags(t_ls *ls, char *sub);
void				ft_get_info(t_ls *ls);
void				ft_printing(t_ls *ls);
void				ft_recursive(t_ls *ls, char *sub);
void				ft_seconds(t_ls *ls);
void				ft_get_path(t_ls *ls);
void				ft_link(t_files *list, size_t bufsize);
void				ft_check_width(int width, int nbr);
void				ft_parse_link(char *name);
void				ft_width(int len, int *width);
void				ft_sort_dirs(t_dirs *d, char *flags, int params);
void				ft_file_sorting(t_ls *ls, char *flags);
void				ft_no_such(char **dir);
void				ft_del_array(char **dir);
void				ft_del_files(t_ls *ls);
void				ft_del_dirs(t_dirs *d);
void				ft_sort_time(t_files *first, int r);
void				ft_sort_names(t_files *first, int r);
void				ft_add_elem(t_files *first, char *name);
void				ft_error(char *s);

int					ft_read_dir(char *file, char *sub);
int					ft_if_total(t_ls *ls);
int					ft_delete(t_ls *ls);
int					ft_check_params(char **av, char *flags, int i, int count);
int					ft_if_dir(char *file);

#endif
