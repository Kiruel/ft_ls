/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 10:25:36 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/03 18:17:30 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_errno(char *path)
{
	DIR *s_dir;

	s_dir = NULL;
	s_dir = opendir(path);
	if (s_dir == NULL)
		return (errno);
	if (closedir(s_dir) == -1)
		return (-1);
	return (0);
}

char **ft_swap_arg(char *opt, char **path)
{
    char *tmp;
    int 	i;

    i = 0;
    while (path[i] != '\0' && path[i + 1] != 0)
    {
        if (ft_strcmp(path[i], path[i + 1]) < 0 && opt[3] == 'r')
        {
            tmp = path[i];
            path[i] = path[i + 1];
            path[i + 1] = tmp;
        }
        else if (ft_strcmp(path[i], path[i + 1]) > 0)
        {
            tmp = path[i];
            path[i] = path[i + 1];
            path[i + 1] = tmp;
        }
        i++;
    }
    return (path);
}

char    **ft_swap_path(char *opt, char **path)
{
    int 	i;
    char 	**ret;

    i = 0;
    ret = path;
    while (ret[i] != NULL)
    {
        path = ft_swap_arg(opt, ret);
        i++;
    }
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
    if (path == 0)
    	return (0);
    j = 0;
    while (av[i] != '\0')
    {
        path[j] = av[i];
        i++;
        j++;
    }
    path[j] = '\0';
    j = 0;
    path = ft_swap_path(opt, path);
    return (path);
}
