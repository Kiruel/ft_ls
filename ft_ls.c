/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:03:48 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/21 11:03:49 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls()
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
		if (!(file_opened->d_name[0] == '.'))
		{
			ft_putstr(file_opened->d_name);
			ft_putchar('\n');			
		}
	}
	if (closedir(ret) == -1)
	{
		perror("");
		exit(-1);
	}
}
