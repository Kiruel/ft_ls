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
    int     j;
    int     g;
    int     k;
	char	opt[6];
    char    **path;
    S_STAT  stat;

	i = -1;
	while (opt[i++] != '\0')
		opt[i] = '\0';
	i = 0;
    j = 1;
	while (ac > 1 && j < ac)
	{
        i = 0;
        while (av[j][i] != '\0' && av[j][0] == '-')
        {
            if (av[j][i] == 'l')
                opt[0] = 'l';
            if (av[j][i] == 'R')
                opt[1] = 'R';
            if (av[j][i] == 'a')
                opt[2] = 'a';
            if (av[j][i] == 'r')
                opt[3] = 'r';
            if (av[j][i] == 't')
                opt[4] = 't';
            if (av[j][i] == 'R')
                opt[5] = 'R';
            i++;
        }
		j++;
	}
    i = 0;
    path = ft_find_path(ac, av, opt);
    g = 0;
    k = 0;
    while (path[g] != 0)
    {
        if (lstat(path[g], &stat) == -1)
            return (0);
        if (S_ISREG(stat.st_mode))
            k++;
        g++;
    }
    j = 0;
    while (path[j] != '\0')
        j++;
    if (path[0] == NULL)
        ft_ls(opt, ".", j);
    while (path[i] != '\0')
    {
        ft_ls(opt, path[i], j);
        if (path[i + 1] != '\0' && k == 0)
            ft_putchar('\n');
        i++;
    }
	return (0);
}
