/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:03:48 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/21 11:03:49 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_ls()
{
	DIR 		*s_dir;
	s_dirent	*poil;
	t_data *list;

	s_dir = opendir(".");
	list = NULL;
	while ((poil = readdir(s_dir)) != NULL)
	{
		if (poil->d_name[0] != '.')
			list = ft_addlink(list, poil->d_name);
	}
	list = ft_sort_list(list);
	ft_print_list(list);
}
