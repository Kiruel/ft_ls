/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:03:07 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/21 11:03:10 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_ls_a()
{
	DIR 		*s_dir;
	s_dirent	*poil;
	t_data 		*list;

	list = NULL;
	s_dir = opendir(".");
	while ((poil = readdir(s_dir)) != NULL)
		list = ft_addlink(list, poil->d_name);
	list = ft_sort_list(list);
	ft_print_list(list);
}
