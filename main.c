/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 09:13:37 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/12 15:11:42 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	*opt;
	char	**path;
	S_STAT	stat;

	k = 0;
	opt = ft_find_opt(ac, av);
	if (!opt)
		return (0);
	path = ft_find_path(av, opt);
    j = 0;
	while (path[j] != 0)
	{
		lstat(path[j], &stat);
		if (S_ISREG(stat.st_mode))
			k++;
		j++;
	}
	j = 0;
	while (path[j] != '\0')
		j++;
	if (path[0] == NULL)
		ft_ls(opt, ".", j);
    i = 0;
	while (path[i] != '\0')
	{
		ft_ls(opt, path[i], j);
		if (path[i + 1] != '\0' && k == 0)
			ft_putchar('\n');
		i++;
	}
	return (0);
}
