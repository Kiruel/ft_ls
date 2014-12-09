/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:05:18 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/27 09:33:22 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_strichr(const char *s, int c)
{
	int i;

	i = (int)ft_strlen((char*)s);
	while (i >= 0)
	{
		if ((char)s[i] == (char)c)
			return (i + 1);
		i--;
	}
	return (0);
}

void	ft_print_list(t_data *list, char *opt, char *path, int k)
{
	t_data	*tmp2;
	t_data 	*tmp;
	int 	*size;
	int		i;

	i = 0;
	size = ft_count_space(list, opt);
	tmp2 = list;
	tmp = list;
	while (tmp2 != NULL)
	{
		if (path[ft_strichr(path, '/')] != '.' && opt[5] == 'R')
			ft_print_l(tmp2, opt, size);
		else
			ft_print_l(tmp2, opt, size);
		tmp2 = tmp2->next;
	}
	free(size);
}
