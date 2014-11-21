/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:03:07 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/21 11:03:10 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_a()
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
