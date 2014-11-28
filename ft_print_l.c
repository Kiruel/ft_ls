/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 11:27:50 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/28 11:27:51 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_print_l(t_data *tmp, t_data *list)
{
	struct group	*gp;
	char			*rettime;
	int				maxsize;
	int				maxlink;
	t_data			*tmp2;

	maxsize = 0;
	maxlink = 0;
	tmp2 = list;
	while (tmp2 != NULL)
	{
		if (tmp2->sizes > maxsize)
			maxsize = tmp2->sizes;
		if (tmp2->nlink > maxlink)
			maxlink = tmp2->nlink;
		tmp2 = tmp2->next;
	}
	tmp->name_owner = (getpwuid((uid_t)tmp->uid))->pw_name;
	gp = getgrgid((gid_t)tmp->gid);
	rettime = ctime((const time_t*)&tmp->mtimes);
	rettime = ft_strsub(rettime, 4, 12);
	ft_put_permissions(tmp);
	ft_putchar(' ');
	ft_align_right(maxlink, tmp->nlink);
	ft_putnbr(tmp->nlink);
	ft_putchar(' ');
	ft_putstr(tmp->name_owner);
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putstr(gp->gr_name);
	ft_putchar(' ');
	ft_align_right(maxsize, tmp->sizes);
	ft_putnbr(tmp->sizes);
	ft_putchar(' ');
	ft_putstr(rettime);
	ft_putchar(' '); 
}