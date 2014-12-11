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
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# define S_DIRENT struct dirent
# define S_STAT struct stat

typedef struct		s_data
{
	char			*name;
	char			*linkname;
	time_t			mtimes;
	time_t			sizes;
	int				uid;
	int				gid;
	char			*name_owner;
	char			*name_group;
	nlink_t			nlink;
	mode_t			mode;
	int				blocksize;
	dev_t			device;
	struct s_data	*next;
}					t_data;

int					ft_find_hidden_path(char *path, char *opt, t_data *list, int h);
void				ft_print_l(t_data *list, char *opt, int *size);
int					ft_ls(char *opt, char *path, int h);
t_data				*ft_addlink(char *path, char *str);
void				ft_print_list(t_data *list, char *opt, char *path, int k);
t_data				*ft_sort_list(t_data **begin, char *opt);
void				ft_swap_brick(t_data *tmp, t_data **begin);
void				ft_list_reverse(t_data **begin_list);
void				ft_align_right(int maxnbr, int size);
int					*ft_count_space(t_data *list, char *opt);
void				ft_add_space_owner(int max_size, int size_owner);
char    			**ft_find_path(int ac, char **av, char *opt);
void 				ft_recursive(t_data *list, char *opt, char *path, int h);
char				*ft_mega_join(char *path, char *backslash, char *name);
int					ft_return_index(char *path);

#endif
