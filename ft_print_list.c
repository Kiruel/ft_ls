/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:05:18 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/23 17:05:20 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/ft_ls.h"

void	ft_print_list(t_data *list)
{
	t_data	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_putendl(tmp->name);
		ft_putnbr(tmp->ctimes);
		tmp = tmp->next;
	}
}
