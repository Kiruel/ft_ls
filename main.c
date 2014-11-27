/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 09:13:37 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/27 09:26:34 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int	main(int ac, char **av)
{
	int		i;
	char	opt[5];
    DIR         *s_dir;

    if (ac == 2 || ac == 1)
        s_dir = opendir(".");
    else
        s_dir = opendir(av[2]);
	i = -1;
	while (opt[i++] != '\0')
		opt[i] = '\0';
	i = 0;
	while (ac > 1 && av[1][i] != '\0' && av[1][0] == '-')
	{
		if (av[1][i] == 'l')
			opt[0] = 'l';
		if (av[1][i] == 'R')
			opt[1] = 'R';
		if (av[1][i] == 'a')
			opt[2] = 'a';
		if (av[1][i] == 'r')
			opt[3] = 'r';
		if (av[1][i] == 't')
			opt[4] = 't';
		i++;
	}
	ft_ls(opt, s_dir);
	return (0);
}
