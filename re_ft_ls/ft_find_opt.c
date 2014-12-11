/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 16:00:36 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/11 16:00:37 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int ft_complet_opt(char *opt, char av)
{
	if (av != 'a' && av != 'l' && av != 'r' && av != 't' && av != 'R')
	{
		write(2, "ft_ls: illegal option -- ", 25);
		write(2, &av, 1);
		write(2, "\n", 1);
		write(2, "usage: ft_ls [-alrtR] [file ...]\n", 33);
		return (-1);
	}
	if (av == 'a')
		opt[0] = 'a';
	if (av == 'l')
		opt[1] = 'l';
	if (av == 'r')
		opt[2] = 'r';
	if (av == 't')
		opt[3] = 't';
	if (av == 'R')
		opt[4] = 'R';
	return (0);
}

char *ft_find_opt(int ac, char **av)
{
	char 	*opt;
	int 	i;
	int 	j;

	opt = (char*)malloc(sizeof(char) * 5);
	if (opt == 0)
		return (0);
	ft_bzero(opt, 5);
	i = 0;
    j = 1;
	while (ac > 1 && j < ac)
	{
        i = 1;
        while (av[j][i] != '\0' && av[j][0] == '-')
        {
			if (ft_complet_opt(opt, av[j][i]) == -1)
				return (0);
			i++;
        }
        j++;
	}
	return (opt);
}
