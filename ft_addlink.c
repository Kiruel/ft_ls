/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:06:12 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/27 09:38:16 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char	*ft_mega_join(char *path, char *backslash, char *name)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin(path, backslash);
	tmp2 = ft_strjoin(tmp, name);
	free(tmp);
	return (tmp2);
}

t_data	*ft_addlink(char *path, char *str)
{
	t_data	*brick;
	S_STAT	megapoil;

	path = ft_mega_join(path, "/", str);
	(void)lstat(path, &megapoil);
	brick = (t_data*)malloc(sizeof(t_data));
	if (brick == 0)
		return (NULL);
	brick->mtimes = megapoil.st_mtime;
	brick->sizes = (int)megapoil.st_size;
	brick->uid = (int)megapoil.st_uid;
	brick->gid = (int)megapoil.st_gid;
	brick->nlink = (int)megapoil.st_nlink;
	brick->mode = megapoil.st_mode;
	brick->name = str;
	brick->blocksize = (int)megapoil.st_blocks;
	brick->next = NULL;
	free(path);
	return (brick);
}
