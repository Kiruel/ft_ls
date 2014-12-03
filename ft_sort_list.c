/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:18:26 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/03 18:27:14 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_data	*ft_sort_list(t_data **begin, char *opt)
{
	t_data	*tmp;
	int		i;

	i = 1;
	while (i)
	{
		i = 0;
		tmp = *begin;
		while (tmp->next)
		{
			if (tmp->mtimes < tmp->next->mtimes && opt[4] == 't')
			{
				i = 1;
				ft_swap_brick(tmp, begin);
			}
			else if (ft_strcmp(tmp->name, tmp->next->name) > 0 && opt[4] != 't')
			{
				i = 1;
				ft_swap_brick(tmp, begin);
			}
			else
				tmp = tmp->next;
		}
	}
	if (opt[3] == 'r')
		ft_list_reverse(begin);
	return (*begin);
}
