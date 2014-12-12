/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 11:27:50 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/12 11:06:46 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void		ft_print_device(t_data *tmp, int *size)
{
	ft_align_right_now(size[3], major(tmp->device));
	ft_add_space_owner(size[5], ft_strlen(tmp->name_group));
	ft_putchar(' ');
	ft_putnbr(major(tmp->device));
	ft_putstr(", ");
	ft_align_right_now(size[4], minor(tmp->device));
	ft_putnbr(minor(tmp->device));
}

void		ft_print_link(t_data *tmp, int *size)
{
	ft_put_permissions(tmp);
	ft_align_right(size[1], tmp->nlink);
	ft_putnbr(tmp->nlink);
	ft_putchar(' ');
	ft_putstr(tmp->name_owner);
	ft_add_space_owner(size[2], ft_strlen(tmp->name_owner));
	ft_putstr(tmp->name_group);
}

void		ft_coffee(t_data *tmp, int *size)
{
	char	*rettime;
	char	*if_time_sup;

	rettime = ctime(&tmp->mtimes);
	if_time_sup = ctime(&tmp->mtimes);
	ft_print_link(tmp, size);
	if (S_ISCHR(tmp->mode) || S_ISBLK(tmp->mode))
		ft_print_device(tmp, size);
	else
		ft_print_fail(tmp, size);
	ft_putchar(' ');
	ft_print_time(tmp, rettime, if_time_sup);
}

void		ft_print_all(t_data *list, char *opt, int *size)
{
	if (opt[0] != 'a')
	{
		if (list->name[0] != '.')
			ft_coffee(list, size);
	}
	else
		ft_coffee(list, size);
}

void		ft_print_l(t_data *list, char *opt, int *size)
{
	if (opt[1] == 'l')
		ft_print_all(list, opt, size);
	else
	{
		if (opt[0] == 'a')
			ft_putendl(list->name);
		if (opt[0] != 'a')
		{
			if (list->name[0] != '.')
				ft_putendl(list->name);
		}
	}
}
