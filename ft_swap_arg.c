/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 09:52:52 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/03 09:52:53 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char **ft_swap_arg(char *opt, char **path, int i)
{
	char *tmp;
	
	while (path[i] != '\0' && path[i + 1] != 0)
	{
		if (opt[3] == 'r')
		{  
			if (ft_strcmp(path[i], path[i + 1]) < 0)
			{
				tmp = path[i];
				path[i] = path[i + 1];
				path[i + 1] = tmp;
			}
		}
		else
		{
			if (ft_strcmp(path[i], path[i + 1]) > 0)
			{
				tmp = path[i];
				path[i] = path[i + 1];
				path[i + 1] = tmp;
			}
		}
		i++;
	}
	return (path);
}