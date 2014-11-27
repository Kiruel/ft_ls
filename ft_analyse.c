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

DIR		*ft_analyse(int ac, char **av, DIR *s_dir)
{
	t_data *tmp;

/*	while (ac != 0)
	{
		
	}*/
	// if (ac == 2 && )
    // if (ac == 1)
        s_dir = opendir(".");
/*    else
        s_dir = opendir(av[2]);*/
    return (s_dir);
}