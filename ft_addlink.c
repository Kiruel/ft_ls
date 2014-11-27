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

t_data	*ft_addlink(t_data *list, char *path, char *str)
{
	t_data	*brick;
	t_data	*tmp;
	S_STAT	megapoil;

	tmp = list;
	path = ft_mega_join(path, "/", str);
	(void)stat(path, &megapoil);
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
	if (list == NULL)
	{
		brick->next = NULL;
		return (brick);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = brick;
	brick->next = NULL;
	return (list);
}
