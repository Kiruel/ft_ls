/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:06:12 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/03 18:55:07 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_complet_brick(t_data **brick, S_STAT megapoil)
{
	(*brick)->mtimes = megapoil.st_mtime;
	(*brick)->sizes = (int)megapoil.st_size;
	(*brick)->nlink = megapoil.st_nlink;
	(*brick)->mode = megapoil.st_mode;
	(*brick)->blocksize = (int)megapoil.st_blocks;
	(*brick)->device = megapoil.st_rdev;
}

void	ft_complet_link(t_data **brick, S_STAT megapoil, char *path)
{
	struct group	*gp;
	int				ret;

	gp = getgrgid((gid_t)(*brick)->gid);
	if (gp == NULL)
		exit (1);
	(*brick)->linkname = (char*)malloc(megapoil.st_size + 1);
	ret = 0;
	if (S_ISLNK(megapoil.st_mode))
		ret = readlink(path, (*brick)->linkname, megapoil.st_size);
	if (ret == -1)
	{
		perror("");
		exit (1);
	}
	(*brick)->linkname[ret] = 0;
	(*brick)->name_group = gp->gr_name;
}

t_data	*ft_addlink(char *path, char *str)
{
	t_data			*brick;
	S_STAT			megapoil;
	struct passwd	*pwd;

	path = ft_mega_join(path, "/", str);
	if (lstat(path, &megapoil) == -1)
		return (NULL);
	brick = (t_data*)malloc(sizeof(t_data));
	if (brick == 0)
		return (NULL);
	brick->uid = (int)megapoil.st_uid;
	brick->gid = (int)megapoil.st_gid;
	if ((pwd = getpwuid(brick->uid)))
		brick->name_owner = pwd->pw_name;
	else
		brick->name_owner = ft_itoa(brick->uid);
	ft_complet_link(&brick, megapoil, path);
	ft_complet_brick(&brick, megapoil);
	brick->name = ft_strdup(str);
	brick->next = NULL;
	free(path);
	return (brick);
}
