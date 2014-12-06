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

t_data	*ft_addlink(char *path, char *str)
{
	t_data	*brick;
	S_STAT	megapoil;
	struct group	*gp;
	struct passwd	*pwd;

	path = ft_mega_join(path, "/", str);
	(void)lstat(path, &megapoil);
	brick = (t_data*)malloc(sizeof(t_data));
	if (brick == 0)
		return (NULL);
	brick->uid = (int)megapoil.st_uid;
	brick->gid = (int)megapoil.st_gid;	
	if ((pwd = getpwuid(brick->uid)))
		brick->name_owner = pwd->pw_name;
	else
		brick->name_owner = ft_itoa(brick->uid);
	gp = getgrgid((gid_t)brick->gid);
	brick->name_group = gp->gr_name;
	brick->mtimes = megapoil.st_mtime;
	brick->sizes = (int)megapoil.st_size;
	brick->nlink = megapoil.st_nlink;
	brick->mode = megapoil.st_mode;
	brick->name = ft_strdup(str);
	brick->blocksize = (int)megapoil.st_blocks;
	brick->next = NULL;
	free(path);
	return (brick);
}
