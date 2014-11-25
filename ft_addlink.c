/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:06:12 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/23 17:06:13 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/ft_ls.h"

t_data	*ft_addlink(t_data *list, char *str)
{
	t_data 	*brick;
	t_data 	*tmp;
	s_stat	megapoil;

	tmp = list;
	(void)stat(str, &megapoil);
	brick = (t_data*)malloc(sizeof(t_data));
	if (brick == 0)
		return (NULL);
	brick->mtimes = megapoil.st_mtime;
	brick->sizes = (int)megapoil.st_size;
	brick->uid = (int)megapoil.st_uid;
	brick->gid = (int)megapoil.st_gid;
	brick->name = str;
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
