/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 11:05:36 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/26 11:05:46 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_align_right(int maxnbr, t_data *list)
{
	t_data *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		
		tmp = tmp->next;
	}
	ft_putchar(' ');
}