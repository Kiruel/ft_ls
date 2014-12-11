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

char *ft_find_opt(int ac, char *av);

#endif
