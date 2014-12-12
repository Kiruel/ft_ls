/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:18:26 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/12 10:21:22 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_swap_time(t_data **begin)
{
	int		i;
	t_data	*tmp;

	i = 1;
	while (i)
	{
		i = 0;
		tmp = *begin;
		while (tmp->next)
		{
			if (tmp->mtimes < tmp->next->mtimes)
			{
				i = 1;
				ft_swap_brick(tmp, begin);
			}
			else
				tmp = tmp->next;
		}
	}
}

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
			if (ft_strcmp(tmp->name, tmp->next->name) > 0)
			{
				i = 1;
				ft_swap_brick(tmp, begin);
			}
			else
				tmp = tmp->next;
		}
	}
	if (opt[3] == 't')
		ft_swap_time(begin);
	if (opt[2] == 'r')
		ft_list_reverse(begin);
	return (*begin);
}
