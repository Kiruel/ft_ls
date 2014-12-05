/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:03:48 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/03 19:00:17 by etheodor         ###   ########.fr       */
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
		if (errno == ENOTDIR)
		{
			*list = ft_addlink(".", path);
			return (0);
		}
		else
		{
			ft_putstr("ft_ls: ");
			ft_putstr(path);
			ft_putstr(": ");
			perror("");
			return (-1);
		}
		return (-1);
	}
	poil = readdir(s_dir);
	*list = ft_addlink(path, poil->d_name);
	tmp = *list;
	while ((poil = readdir(s_dir)) != NULL)
	{
		tmp->next = ft_addlink(path, poil->d_name);
		tmp = tmp->next;
	}
	if (closedir(s_dir))
		return (0);
	return (0);
}

int		ft_ls(char *opt, char *path, char **path_str)
{
	S_DIRENT	*poil;
	t_data 		*list;
	int			i;
	int			j;
	t_data		*tmp2;

	i = 0;
	if (ft_create_chain(path, &list, opt) == -1)
		return (0);
	while (path_str[i] != NULL)
		i++;
	if (S_ISDIR(list->mode) && i > 1)
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	j = 0;
	if (opt[0] == 'l' && (S_ISDIR(list->mode)))
	{
		tmp2 = list;
		ft_putstr("total ");
		while (tmp2 != NULL)
		{
			j += tmp2->blocksize;
			tmp2 = tmp2->next;
		}
		ft_putnbr(j);
		ft_putchar('\n');
	}
	j = 0;
	while (path_str[j] != path && path_str[j] != NULL)
		j++;
	list = ft_sort_list(&list, opt);
	ft_print_list(list, opt, path, path_str);
	if (i > 1 && !(j == i - 1))
		ft_putchar('\n');
	if (opt[5] == 'R')
		ft_recursive(list, opt, path_str);
	ft_free_list(&list);
	return (0);
}
