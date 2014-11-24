/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlink_stats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 17:46:01 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/24 17:46:02 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_data	*ft_addlink_stats_end(t_data *list, s_stat sb)
{	
	t_data 	*tmp;
	t_data 	*brick;
	int 	i;

	i = 0;
	tmp = list;
	brick = (t_data*)malloc(sizeof(t_data));
	if (brick == 0)
		return (NULL);
	brick->ctimes = sb.st_ctime;
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

t_data	*ft_addlink_stats(t_data *list, DIR *s_dir)
{
	s_dirent	*poil;
	s_stat		sb;

	while ((poil = readdir(s_dir)) != NULL)
	{
		list = ft_addlink_stats_end(list, sb);
	}
	return (list);
}
