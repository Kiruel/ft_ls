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

void ft_recursive(t_data *list, char *opt, char **path_str)
{
	t_data *tmp2;
	int i;

	i = 0;
	tmp2 = list;
	while (tmp2 != NULL)
	{
		if (tmp2->name[i] != '.')
			if (S_ISDIR(tmp2->mode) && opt[5] == 'R')
			{
				ft_putstr("./");
				ft_putstr(tmp2->name);
				ft_putstr(":\n");
				ft_ls(opt, ft_strjoin(tmp2->name, "/"), path_str);
				ft_putchar('\n');
			}
		tmp2 = tmp2->next;
		i++;
	}
}
