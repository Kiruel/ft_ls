/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:23:37 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/27 11:23:38 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

DIR		*ft_analyse(int ac, char **av, char *path, char *opt)
{
	t_data *tmp;
	int 	j;
	t_data *list;
	DIR *s_dir;

	list = NULL;
	s_dir = opendir(path);
	if (s_dir == NULL)
	{
		if (errno == ENOTDIR)
		{
			list = ft_addlink(list, ".", path);
			if (opt[0] == 'l')
			{
				ft_print_l(list, list);
				ft_putendl(path);
			}
			else
			{
				ft_putstr(path);
				ft_putchar('\n');
			}
		}
		else
			perror("");
		exit(1);
	}
	j = 1;
	while (ac > 1 && j < ac)
	{
		if (av[j][0] != '-')
			s_dir = opendir(av[j]);
		j++;
	}
    return (s_dir);
}