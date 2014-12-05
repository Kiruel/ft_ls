/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:05:18 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/27 09:33:22 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"


void	ft_print_list(t_data *list, char *opt, char *path)
{
	t_data	*tmp2;
	t_data 	*tmp;
	int 	*size;
	int 	i;
	int 	j;

	size = ft_count_space(list, opt);
	tmp2 = list;
	tmp = list;
	while (tmp2 != NULL)
	{
		ft_print_l(tmp2, tmp, opt, size);
		tmp2 = tmp2->next;
	}	
	free(size);
}
