/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_hidden_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:47:35 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/08 09:47:36 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_find_hidden_path(char *path, char *opt, t_data *list, int h)
{
	int 	i;
	int 	j;
	int 	k;
	t_data 	*tmp2;

	k = 0;
	j = 0;
	i = 0;
	while (path[i] != '\0')
		i++;
	while (path[j] != '\0')
	{
		if (path[j] == '/')
			k++;
		j++;
	}
	j = 0;
	if (opt[0] == 'l' && (S_ISDIR(list->mode)) && path[i + 1] != '.')
	{
		tmp2 = list;
		ft_putstr("total ");
		while (tmp2 != NULL)
		{
			j += tmp2->blocksize;
			tmp2 = tmp2->next;
		}
		ft_putnbr(j);
		ft_putchar('\n');
	}
	if ((!(path[0] == '.' && path[1] == 0)) && opt[5] == 'R')
	{
		if (path[i + 1] != '.')
		{
			ft_putstr(path);
			ft_putstr(":\n");
		}
	}	
	return (i);
}
