/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 15:22:10 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/20 15:45:35 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	int i;

	i = 2;
	if (ac > 2)
	{
		while (i < ac)
		{
			ft_putstr("ft_ls: ");
			ft_putstr(av[i]);
			ft_putstr(": No such file or directory\n");
			i++;
		}
		return (0);
	}
	if (ac == 1)
	{
		ft_ls();
		return (0);
	}
	if (!(ft_strcmp(av[1], "-a")))
	{
		ft_ls_a();
		return (0);
	}
	return (0);
}
