/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_permissions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 11:33:46 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/28 11:33:47 by etheodor         ###   ########.fr       */
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
