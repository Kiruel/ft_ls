/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 11:08:08 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/12 11:08:09 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void ft_print_fail(t_data *tmp, int *size)
{
	int		i;
	t_data	*tmp2;

	i = 0;
	tmp2 = tmp;
	while (tmp2 != NULL)
	{
		if (S_ISCHR(tmp2->mode) || S_ISBLK(tmp2->mode))
			i++;
		tmp2 = tmp2->next;
	}
	if (i > 0)
		ft_putstr("            ");
	ft_align_right(size[0], tmp->sizes);
	ft_putnbr(tmp->sizes);
}
