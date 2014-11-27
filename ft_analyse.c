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
	int j;

	s_dir = opendir(".");
	j = 1;
	while (ac > 1 && j < ac)
	{
		if (av[j][0] != '-')
			s_dir = opendir(av[j]);
		j++;
	}
    return (s_dir);
}