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

void ft_recursive(t_data *list, char *opt, char *path, int h)
{
	t_data *tmp2;
	char *ret;
	int i;

	i = 0;
	tmp2 = list;
	while (tmp2 != NULL)
	{
		if (S_ISDIR(tmp2->mode) && tmp2->name[i] != '.')
		{
			ret = ft_mega_join(path, "/", tmp2->name);
			if (!(path[0] == '.' && path[1] == '\0'))
				ft_putchar('\n');
			ft_ls(opt, ret, h);
		}
		i++;
		tmp2 = tmp2->next;
	}
}
