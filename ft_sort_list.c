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

t_data	*ft_sort_list(t_data *begin)
{
	t_data *tmp;

	tmp = begin;
	while (tmp->next != 0)
	{
		if (ft_strcmp(tmp->name, tmp->next->name) > 0)
			ft_swap_brick(tmp, begin);
		tmp = tmp->next;
	}
	return (begin);
}
