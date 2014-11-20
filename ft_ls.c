/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 15:22:10 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/20 15:45:35 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft/includes/libft.h"

void	ft_l_l()
{
	DIR *ret = NULL;
	struct dirent *file_opened = NULL;

	ret = opendir(".");
	if (ret == NULL)
	{
		perror("");
		exit(1);
	}
	while ((file_opened = readdir(ret)) != 0)
	{
		ft_putstr(file_opened->d_name);
		ft_putchar('\n');
	}
	if (closedir(ret) == -1)
	{
		perror("");
		exit(-1);
	}
}

int		main(int ac, char **av)
{
	if (!(ft_strcmp(av[1], "-a")))
		ft_l_l();
	ac++;
	return (0);
}
