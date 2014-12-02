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


void	ft_print_list(t_data *list, char *opt, char *path, char **path_str)
{
	t_data	*tmp2;
	int		blocksize;
	t_data 	*tmp;
	int 	*size;
	int 	i;

	size = ft_count_space(list, opt);
	tmp2 = list;
	blocksize = 0;
	while (path_str[i] != NULL)
		i++;
	if (S_ISDIR(list->mode) && i > 1)
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (opt[0] == 'l' && (S_ISDIR(list->mode)))
	{
		tmp2 = list;
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
		ft_print_l(tmp2, tmp, opt, size);
		tmp2 = tmp2->next;
	}
	free(size);
}
