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

void	ft_put_permissions(t_data *per)
{
	if (S_ISBLK(per->mode))
		ft_putchar('b');
	else if (S_ISCHR(per->mode))
		ft_putchar('c');
	else if (S_ISDIR(per->mode))
		ft_putchar('d');
	else if (S_ISLNK(per->mode))
		ft_putchar('l');
	else if (S_ISSOCK(per->mode))
		ft_putchar('s');
	else if (S_ISFIFO(per->mode))
		ft_putchar('p');
	else
		ft_putchar('-');
	ft_putstr((per->mode & S_IRUSR) ? "r" : "-");
	ft_putstr((per->mode & S_IWUSR) ? "w" : "-");
	ft_putstr((per->mode & S_IXUSR) ? "x" : "-");
	ft_putstr((per->mode & S_IRGRP) ? "r" : "-");
	ft_putstr((per->mode & S_IWGRP) ? "w" : "-");
	ft_putstr((per->mode & S_IXGRP) ? "x" : "-");
	ft_putstr((per->mode & S_IROTH) ? "r" : "-");
	ft_putstr((per->mode & S_IWOTH) ? "w" : "-");
	ft_putstr((per->mode & S_IXOTH) ? "x" : "-");
}

void	ft_coffee(t_data *tmp, int *size)
{
	char	*rettime;
	char	*linkname;
	char	*if_time_sup;

	rettime = ctime(&tmp->mtimes);
	if_time_sup = ctime(&tmp->mtimes);
	ft_put_permissions(tmp);
	ft_align_right(size[1], tmp->nlink);
	ft_putnbr(tmp->nlink);
	ft_putchar(' ');
	ft_putstr(tmp->name_owner);
	ft_add_space_owner(size[2], ft_strlen(tmp->name_owner));
	ft_putstr(tmp->name_group);
	ft_align_right(size[0], tmp->sizes);
	ft_putnbr(tmp->sizes);
	ft_putchar(' ');
	if (tmp->mtimes < ((int)time(NULL) - 13042800))
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

void	ft_print_all(t_data *list, t_data *tmp, char *opt, int *size)
{
	if (opt[2] != 'a')
	{
		if (tmp->name[0] != '.')
			ft_coffee(tmp, size);		
	}
	else
		ft_coffee(tmp, size);
}

void	ft_print_l(t_data *tmp, t_data *list, char *opt, int *size)
{
	if (opt[0] == 'l')
		ft_print_all(list, tmp, opt, size);
	else
	{
		if (opt[2] == 'a')
			ft_putendl(tmp->name);
		if (opt[2] != 'a')
		{
			if (tmp->name[0] != '.')
				ft_putendl(tmp->name);			
		}
	}
}
