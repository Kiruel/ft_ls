/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_right_now.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 10:42:40 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/12 10:42:41 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static int	ft_patate(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void		ft_align_right_now(int maxnbr, int size)
{
	int i;
	int j;

	i = ft_patate(size);
	j = ft_patate(maxnbr);
	if (i == 0)
		i++;
	while (i < j)
	{
		ft_putchar(' ');
		i++;
	}
}
