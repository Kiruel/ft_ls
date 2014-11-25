/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:05:18 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/25 09:06:48 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/ft_ls.h"

void	ft_print_list(t_data *list, char *opt)
{
	t_data	*tmp;
	char *rettime;

	tmp = list;
	while (tmp != NULL)
	{
		rettime = ctime((const time_t *)&tmp->mtimes);
		rettime = ft_strsub(rettime, 4, 12);
		if (opt[0] == 'l')
		{
			ft_putstr(rettime);
			ft_putchar(' ');
		}
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}
