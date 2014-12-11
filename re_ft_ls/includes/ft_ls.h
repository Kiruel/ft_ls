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
	mode_t			mode;
	int				blocksize;
	char			*name_owner;
	int				uid;	
	char			*name_group;
	int				gid;	
	int				size;
	time_t			mtimes;
	nlink_t			nlink;
	char			*name;
	char			*linkname;	
	dev_t			device;
	struct s_data	*next;
}					t_data;
typedef struct 		s_dir
{
	t_data 			*list;
	int				total_block;
	int				isfile;
	int				max_size;
	int				max_link;
	int				max_name_owner;
	int				max_name_group;
	int				max_major;
	int				max_minor;
}					t_dir;

char 	*ft_find_opt(int ac, char **av);
char 	**ft_find_path(int ac, char **av);
t_dir 	*ft_create_chain(t_dir *chain, char *path, char *opt);

#endif
