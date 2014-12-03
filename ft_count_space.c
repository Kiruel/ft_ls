/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:11:48 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/01 17:11:49 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		*ft_count_space(t_data *list, char *opt)
{
	t_data			*tmp2;
	int				*size;
	t_data			*tmp;

	size = (int*)malloc(sizeof(int) * 3);
	tmp2 = list;
	tmp = list;
	size[0] = 0;
	size[1] = 0;
	size[2] = 0;
	while (tmp2 != NULL && tmp != NULL)
	{
		if (tmp2->sizes > size[0])
			size[0] = tmp2->sizes;
		while (tmp->name[0] == '.' && opt[2] != 'a')
			tmp = tmp->next;
		if (tmp->nlink > size[1])
				size[1] = tmp->nlink;
			tmp = tmp2;
		if (ft_strlen(tmp2->name_owner) > size[2])
			size[2] = ft_strlen(tmp2->name_owner);
		tmp2 = tmp2->next;
		tmp = tmp->next;
	}
	return (size);
}