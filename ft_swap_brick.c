/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_brick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 18:16:28 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/23 18:16:30 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_swap_brick(t_data *tmp, t_data **begin)
{
	t_data *avant;
	t_data *apres;
	
	if (tmp == *begin)
	{
		apres = tmp->next;
		tmp->next = tmp->next->next;
		apres->next = tmp;
		*begin = apres;
	}
	else
	{
		avant = *begin;
		apres = tmp->next;
		while (avant->next != tmp)
			avant = avant->next;
		avant->next = apres;
		tmp->next = apres->next;
		apres->next = tmp;
	}
}
