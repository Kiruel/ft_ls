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

#include "includes/ft_ls.h"

int		main(int ac, char **av)
{
	int i;
	int j;
	int k;
	int a;

	j = 0;
	i = 2;
	a = 0;
	k = 0;
	if (ac == 1)
	{		
		ft_ls(0);
		return (0);
	}
	if (!(av[1][0] == '-'))
	{
		ft_putstr("ft_ls: ");
		ft_putstr(av[i]);
		ft_putstr(": No such file or directory\n");
		return (0);
	}
	i = 0;
	while (av[i] != 0)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			if (av[i][j] == 'a' && k == 0)
			{
				ft_ls('a');
				k++;
			}
			if (av[i][j] == 'r' && a == 0)
			{
				ft_ls('r');
				a++;
			}
			j++;
		}
		i++;
	}
	return (0);
}
