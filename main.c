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

char    *ft_find_path(int ac, char **av)
{
    char *path;
    int j;
    int i;

    path = ".";
    j = 1;
    i = 1;
    while (av[j] != '\0')
    {
        if (av[j][0] == '-')
            i++;
        j++;
    }
    if (av[i] != 0)
    {
        path = av[i];
        return (path);
    }
    return (path);
}

int	main(int ac, char **av)
{
	int		i;
    int     j;
	char	opt[5];
    DIR     *s_dir;
    char *path;

    s_dir = ft_analyse(ac, av, s_dir);
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
            i++;
        }
		j++;
	}
    path = ft_find_path(ac, av);
	ft_ls(opt, s_dir, path);
	return (0);
}
