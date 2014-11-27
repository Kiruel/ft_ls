/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 11:05:36 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/27 09:39:02 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_patate(int n)
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

void	ft_align_right(int maxnbr, int size)
{
	int i;
	int j;

	i = ft_patate(size);
	j = ft_patate(maxnbr);
	j++;
	while (i < j)
	{
		ft_putchar(' ');
		i++;
	}
}
