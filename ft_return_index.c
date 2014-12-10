/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:39:52 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/10 16:39:53 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_i_strrchr(const char *s, int c)
{
	int i;

	i = (int)ft_strlen((char*)s);
	while (i >= 0)
	{
		if ((char)s[i] == (char)c)
			return (i);
		i--;
	}
	return (0);
}

int		ft_return_index(char *path)
{
	int		i;
	int 	j;

	i = 0;
	j = ft_strlen(path);
	i = ft_i_strrchr(path, '/');
	i++;
	while (j > i)
		j--;
	if (path[j] != '.')
		return (1);
	return (0);
}
