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

int		ft_i_strrchr(const char *s, int c)
{
	int i;

	i = (int)ft_strlen((char*)s);
	while (i >= 0)
	{
		if ((char)s[i] == (char)c)
			return (i);
		i--;
	}
	return (0);
}

void	ft_print_list(t_data *list, char *opt, char *path, int k)
{
	t_data	*tmp2;
	int 	*size;
	int		i;
	int 	j;

	size = ft_count_space(list, opt);
	tmp2 = list;
	i = 0;
	j = ft_strlen(path);
	i = ft_i_strrchr(path, '/');
	i++;
	while (j > i)
		j--;
	while (tmp2 != NULL)
	{
		if (opt[2] != 'a')
		{
			if (path[j] != '.')
				ft_print_l(tmp2, opt, size);
		}
		else
		{
			ft_print_l(tmp2, opt, size);
		}
		tmp2 = tmp2->next;
	}
	free(size);
}
