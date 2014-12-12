/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 10:52:56 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/12 11:05:13 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void ft_print_time(t_data *tmp, char *rettime, char *if_time_sup)
{
	if (tmp->mtimes < ((int)time(NULL) - 15768000))
	{
		rettime = ft_strsub(rettime, 4, 7);
		if_time_sup = ft_strsub(if_time_sup, 19, 5);
		ft_putstr(rettime);
		ft_putstr(if_time_sup);
	}
	else
	{
		rettime = ft_strsub(rettime, 4, 12);
		ft_putstr(rettime);
	}
	ft_putchar(' ');
	if (S_ISLNK(tmp->mode))
	{
		ft_putstr(tmp->name);
		ft_putstr(" -> ");
		ft_putendl(tmp->linkname);
	}
	else
		ft_putendl(tmp->name);
}
