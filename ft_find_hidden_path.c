/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_hidden_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:47:35 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/08 09:47:36 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_path(char *opt, char *path)
{
	if (opt[4] == 'R' && ft_return_index(path))
	{
		if (path[1] != '\0')
		{
			ft_putstr(path);
			ft_putstr(":\n");
		}
	}
	else if (opt[4] == 'R' && opt[0] == 'a')
	{
		if (path[1] != '\0')
		{
			ft_putstr(path);
			ft_putstr(":\n");
		}
	}
}

void	ft_path_total(t_data *tmp2, char *opt)
{
	int j;

	j = 0;
	if (opt[1] == 'l' && (S_ISDIR(tmp2->mode)))
	{
		while (tmp2 != NULL)
		{
			j += tmp2->blocksize;
			tmp2 = tmp2->next;
		}
		ft_putstr("total ");
		ft_putnbr(j);
		ft_putchar('\n');
	}
}

void 	ft_find_hidden_path(char *path, char *opt, t_data *list)
{
	int		i;
	int		j;
	int		k;
	t_data	*tmp2;

	k = 0;
	j = 0;
	i = 0;
	while (path[i] != '\0')
		i++;
	while (path[j] != '\0')
	{
		if (path[j] == '/')
			k++;
		j++;
	}
	ft_path(opt, path);
	tmp2 = list;
	ft_path_total(tmp2, opt);
}
