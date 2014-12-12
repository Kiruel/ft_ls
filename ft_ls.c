/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:03:48 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/12 13:04:53 by etheodor         ###   ########.fr       */
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

int		ft_if_fail(DIR *s_dir, char *path, t_data **list)
{
	if (s_dir == 0)
	{
		if (errno == ENOTDIR)
		{
			*list = ft_addlink(".", path);
			return (1);
		}
		else
		{
			write(2, "ft_ls: ", 7);
			ft_putstr_fd(path, 2);
			ft_putstr_fd(": ", 2);
			perror("");
			return (-1);
		}
		return (-1);
	}
	return (0);
}

int		ft_create_chain(char *path, t_data **list)
{
	DIR			*s_dir;
	S_DIRENT	*poil;
	t_data		*tmp;

	s_dir = opendir(path);
	if (ft_if_fail(s_dir, path, list) == -1)
		return (-1);
	else if (ft_if_fail(s_dir, path, list) == 1)
		return (0);
	poil = readdir(s_dir);
	*list = ft_addlink(path, poil->d_name);
	tmp = *list;
	while ((poil = readdir(s_dir)) != NULL && tmp != NULL)
	{
		tmp->next = ft_addlink(path, poil->d_name);
		tmp = tmp->next;
	}
	if (closedir(s_dir))
		return (0);
	return (0);
}

int		ft_ls(char *opt, char *path, int h)
{
	t_data		*list;
	int			i;
	static int	g = 0;

	i = 0;
	if (ft_create_chain(path, &list) == -1)
		return (0);
	while (path[i] != '\0')
		i++;
	if (S_ISDIR(list->mode) && opt[4] != 'R' && h > 1)
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (opt[4] == 'R' || opt[1] == 'l')
		ft_find_hidden_path(path, opt, list);
	list = ft_sort_list(&list, opt);
	ft_print_list(list, opt, path);
	if (g == 0 && opt[0] == 'a' && opt[2] != 'r' && opt[4] == 'R')
		ft_putchar('\n');
	g++;
	if (opt[4] == 'R')
		ft_recursive(list, opt, path, h);
	ft_free_list(&list);
	return (0);
}
