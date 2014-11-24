/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:18:26 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/23 17:18:41 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_data	*ft_sort_list(t_data *begin, char r)
{
	t_data *tmp;
	int i;

	i = 1;
	while (i)
	{
		i = 0;
		tmp = begin;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->name, tmp->next->name) < 0  && r == 'r')
			{
				i = 1;
				ft_swap_brick(tmp, &begin);
			}
			else
				tmp = tmp->next;
			if (ft_strcmp(tmp->name, tmp->next->name) > 0)
			{
				i = 1;
				ft_swap_brick(tmp, &begin);
			}
			else
				tmp = tmp->next;
		}
	}
	return (begin);
}
