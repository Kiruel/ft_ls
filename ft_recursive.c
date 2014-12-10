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

	tmp2 = list;
	while (tmp2 != NULL)
	{
		if (S_ISDIR(tmp2->mode) && (ft_strcmp(tmp2->name, ".") && ft_strcmp(tmp2->name, "..")))
		{
			ret = ft_mega_join(path, "/", tmp2->name);
			if (ft_return_index(ret))
				ft_putchar('\n');
			ft_ls(opt, ret, h);
			free(ret);
		}
		tmp2 = tmp2->next;
	}
}
