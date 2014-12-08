/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 14:57:37 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/05 14:57:38 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void ft_recursive(t_data *list, char *opt, char *path, char **path_str)
{
	t_data *tmp2;
	int i;
	char *ret;

	i = 0;
	tmp2 = list;
	while (tmp2 != NULL)
	{
		if (S_ISDIR(tmp2->mode) && tmp2->name[i] != '.')
		{
			ret = ft_mega_join(path, "/", tmp2->name);
			ft_ls(opt, ret, path_str);
		}
		tmp2 = tmp2->next;
		i++;
	}
}
