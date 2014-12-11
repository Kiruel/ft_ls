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

	size = (int*)malloc(sizeof(int) * 5);
	tmp2 = list;
	size[0] = 0;
	size[1] = 0;
	size[2] = 0;
	size[3] = 0;
	size[4] = 0;
	size[5] = 0;
	while (tmp2 != NULL)
	{
		if (opt[2] == 'a')
		{
			if (tmp2->sizes > size[0])
				size[0] = tmp2->sizes;
			if (tmp2->nlink > size[1])
				size[1] = tmp2->nlink;
			if (ft_strlen(tmp2->name_owner) > size[2])
				size[2] = ft_strlen(tmp2->name_owner);
			if (major(tmp2->device) > size[3])
				size[3] = major(tmp2->device);
			if (minor(tmp2->device) > size[4])
				size[4] = minor(tmp2->device);
			if (ft_strlen(tmp2->name_group) > size[5])
				size[5] = ft_strlen(tmp2->name_group);
		}
		else
		{
			if (tmp2->name[0] != '.')
			{
				if (tmp2->sizes > size[0])
					size[0] = tmp2->sizes;
				if (tmp2->nlink > size[1])
					size[1] = tmp2->nlink;
				if (ft_strlen(tmp2->name_owner) > size[2])
					size[2] = ft_strlen(tmp2->name_owner);
				if (major(tmp2->device) > size[3])
					size[3] = major(tmp2->device);
				if (minor(tmp2->device) > size[4])
					size[4] = minor(tmp2->device);
				if (ft_strlen(tmp2->name_group) > size[5])
					size[5] = ft_strlen(tmp2->name_group);
			}
		}
		tmp2 = tmp2->next;
	}
	return (size);
}
