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

char	**ft_sort_out(char **ptr, struct dirent *file_opened)
{
	int i;

	i = 0;
	while (i < ptr)
	{
		ptr[0][i] = file_opened->d_name;
		i++;
	}
/*	if (!(file_opened->d_name[0] == '.'))
	{
		ft_putstr(file_opened->d_name);
		ft_putchar('\n');
	}*/
}

void	ft_ls()
{
	DIR 			*ret = NULL;
	struct dirent 	*file_opened = NULL;
	char **name;
	int i;

	ret = opendir(".");
	if (ret == NULL)
	{
		perror("");
		exit(1);
	}
	i = 0;
	while ((file_opened = readdir(ret)) != 0)
		i++;
	name = (char**)malloc(sizeof(char*) * i + 1);
	name[0][i] = 0;
	i = 0;
	while ((file_opened = readdir(ret)) != 0)
		ft_sort_out(name, file_opened);
	if (closedir(ret) == -1)
	{
		perror("");
		exit(-1);
	}
}
