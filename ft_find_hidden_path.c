/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_hidden_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:47:35 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/08 09:47:36 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_find_hidden_path(char *path, char *opt, int p, int h)
{
	int i;
	int j;
	int k;

	k = 0;
	j = 0;
	i = 0;
	while (path[i] != '\0')
		i++;
	while (path[i] != '/')
		i--;
	while (path[j] != '\0')
	{
		if (path[j] == '/')
			k++;
		j++;
	}
	if ((!(path[0] == '.' && path[1] == 0)))
	{
		if (path[i + 1] != '.')
		{
			ft_putstr(path);
			ft_putstr(":\n");
		}
	}
	return (i);
}
