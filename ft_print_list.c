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
	struct group *gp;

	tmp = list;
	while (tmp != NULL)
	{
		if (opt[0] == 'l')
		{
			tmp->name_owner = (getpwuid((uid_t)tmp->uid))->pw_name;
			gp = getgrgid((gid_t)tmp->gid);
			rettime = ctime((const time_t*)&tmp->mtimes);
			rettime = ft_strsub(rettime, 4, 12);
			ft_putstr(tmp->name_owner);
			ft_putstr(gp->gr_name);
			ft_putnbr(tmp->sizes);
			ft_putchar(' ');
			ft_putstr(rettime);
			ft_putchar(' ');
		}
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}
