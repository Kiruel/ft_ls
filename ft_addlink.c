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
	int 	i;
	t_data 	*brick;
	t_data 	*tmp;
	s_stat	megapoil;

	tmp = list;
	(void)stat(str, &megapoil);
	brick = (t_data*)malloc(sizeof(t_data));
	brick->mtimes = (int)megapoil.st_mtime;
	if (brick == 0)
		return (NULL);
	i = 0;
	while (i < 256)
	{
		brick->name[i] = str[i];
		i++;
	}
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
