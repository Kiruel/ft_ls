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

char    **ft_swap_path_again(int j, char **path, char *opt)
{
    int i;
    char    *tmp;

    while (j)
    {
        i = 0;
        path = ft_swap_arg(opt, path, i);
        j--;
    }
    return (path);
}

char    **ft_swap_path(char *opt, char **path)
{
    int     i;
    int     j;

    j = 0;
    while (path[j] != 0)
        j++;
    path = ft_swap_path_again(j, path, opt);
    return (path);
}

char    **ft_find_path(int ac, char **av, char *opt)
{
    char **path;
    int j;
    int i;

    j = 1;
    i = 1;
    while (av[j] != '\0')
    {
        if (av[j][0] == '-')
            i++;
        j++;
    }
    j = i;
    while (av[j] != '\0')
        j++;
    path = (char**)malloc(sizeof(char*) * j + 1);
    j = 0;
    while (av[i] != '\0')
    {
        path[j] = av[i];
        i++;
        j++;
    }
    path[j] = '\0';
    path = ft_swap_path(opt, path);
    return (path);
}

int	main(int ac, char **av)
{
	int		i;
    int     j;
	char	opt[6];
    char    **path;

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
    if (path[0] == NULL)
        ft_ls(opt, ".", path);
    while (path[i] != '\0')
    {
        ft_ls(opt, path[i], path);
        i++;
    }
	return (0);
}
