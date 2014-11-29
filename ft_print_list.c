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


void	ft_print_list(t_data *list, char *opt)
{
	t_data	*tmp2;
	int		blocksize;
	t_data *tmp;

	tmp2 = list;
	blocksize = 0;
	if (opt[0] == 'l')
	{
		ft_putstr("total ");
		while (tmp2 != NULL)
		{
			blocksize += tmp2->blocksize;
			tmp2 = tmp2->next;
		}
		ft_putnbr(blocksize);
		ft_putchar('\n');
	}
	tmp2 = list;
	tmp = list;
	while (tmp2 != NULL)
	{
		ft_print_l(tmp2, tmp, opt);
		tmp2 = tmp2->next;
	}
}
