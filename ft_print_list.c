/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:05:18 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/12 10:40:23 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_print_list(t_data *list, char *opt, char *path)
{
	t_data	*tmp2;
	int		*size;

	size = ft_count_space(list, opt);
	tmp2 = list;
	while (tmp2 != NULL)
	{
		if (opt[0] != 'a')
		{
			if (ft_return_index(path))
				ft_print_l(tmp2, opt, size);
		}
		else
		{
			ft_print_l(tmp2, opt, size);
		}
		tmp2 = tmp2->next;
	}
	free(size);
}
