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
	char    *opt;
    char    **path;
    int     i;
    t_dir   *chain;

    opt = ft_find_opt(ac, av);
    if (!opt)
        return (0);
    path = ft_find_path(ac, av);
    i = 0;
    chain = NULL;
    while (path[i] != 0)
    {
        chain = ft_create_chain(chain, path[i], opt);
        chain = chain->next;
        i++;
    }
	return (0);
}
