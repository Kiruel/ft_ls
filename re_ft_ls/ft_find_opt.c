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

void ft_complet_opt(char **opt, char av)
{
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
}

char *ft_find_opt(int ac, char *av)
{
	char opt[5];
	int i;

	opt = ft_strdup(opt);
	i = 0;
    j = 0;
	while (ac > 1 && j++ < ac)
	{
        i = -1;
        while (av[j][i++] != '\0' && av[j][0] == '-')
        {
			ft_complet_opt(&opt, av[j][i]);
        }
	}
	return (opt);
}
