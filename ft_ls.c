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

#include "includes/ft_ls.h"

void	ft_free_list(t_data **list)
{
	t_data *tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(*list);
		*list = tmp;
	}
}

int		ft_create_chain(char *path, t_data **list, char *opt)
{
	DIR *s_dir;
	S_DIRENT *poil;
	t_data *tmp;

	s_dir = opendir(path);
	if (s_dir == 0)
	{
		*list = ft_addlink(".", path);
		if (!(S_ISDIR((*list)->mode)))
			return (0);
		else
		{
			ft_putstr("ft_ls: ");
			ft_putstr(path);
			ft_putstr(": ");
			perror("");
			return (-1);
		}
	}
	poil = readdir(s_dir);
	*list = ft_addlink(path, poil->d_name);
	tmp = *list;
	while ((poil = readdir(s_dir)) != NULL)
	{
		if (poil)
		tmp->next = ft_addlink(path, poil->d_name);
		tmp = tmp->next;
	}
	if (closedir(s_dir))
		return (-1);
	return (0);
}

int		ft_ls(char *opt, char *path)
{
	S_DIRENT	*poil;
	t_data 		*list;

	if (ft_create_chain(path, &list, opt) == -1)
		return (-1);
	list = ft_sort_list(&list, opt);
	ft_print_list(list, opt);
	ft_free_list(&list);
	return (0);
}
