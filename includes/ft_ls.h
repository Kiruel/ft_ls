/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:01:02 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/27 09:46:37 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include "../libft/includes/libft.h"
# define S_DIRENT struct dirent
# define S_STAT struct stat

typedef struct		s_data
{
	char			*name;
	int				mtimes;
	time_t			sizes;
	int				uid;
	int				gid;
	char			*name_owner;
	char			*name_group;
	int				nlink;
	mode_t			mode;
	int				blocksize;
	struct s_data	*next;
}					t_data;

void				*ft_put_permissions(t_data *per);
void				ft_print_l(t_data *tmp, t_data *list);
void				ft_ls(char *opt, DIR *s_dir, char *path);
t_data				*ft_addlink(t_data *list, char *path, char *str);
void				ft_print_list(t_data *list, char *opt);
t_data				*ft_sort_list(t_data **begin, char *opt);
void				ft_swap_brick(t_data *tmp, t_data **begin);
void				ft_list_reverse(t_data **begin_list);
void				ft_align_right(int maxnbr, int size);
DIR					*ft_analyse(int ac, char **av, DIR *s_dir, char *path, char *opt);

#endif
