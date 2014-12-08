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

int		ft_find_hidden_path(char *path, char *opt)
{
	int i;

	i = 0;
	while (path[i] != '\0')
		i++;
	while (path[i] != '/')
		i--;
	if (path[1] == '/' && path[i + 1] != '.')
	{
		ft_putchar('\n');
		ft_putstr(path);
		ft_putstr(":\n");
	}
	return (i);
}
