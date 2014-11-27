/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:05:18 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/27 09:33:22 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	*ft_put_permissions(t_data *per)
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

void	ft_print_l(t_data *tmp, int maxsize, int maxlink)
{
	struct group	*gp;
	char			*rettime;

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

void	ft_print_list(t_data *list, char *opt)
{
	t_data	*tmp2;
	int		blocksize;
	int		maxsize;
	int		maxlink;

	tmp2 = list;
	blocksize = 0;
	if (opt[0] == 'l')
	{
		ft_putstr("total ");
		while (tmp2 != NULL)
		{
			blocksize += tmp2->blocksize;
			tmp2 = tmp2->next;
		}
		ft_putnbr(blocksize);
		ft_putchar('\n');
	}
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
	tmp2 = list;
	while (tmp2 != NULL)
	{
		if (opt[0] == 'l')
			ft_print_l(tmp2, maxsize, maxlink);
		ft_putendl(tmp2->name);
		tmp2 = tmp2->next;
	}
}
