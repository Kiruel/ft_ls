/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:01:02 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/21 11:01:03 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"
# define  s_dirent struct dirent
# define  s_stat struct stat

typedef struct 	s_data
{
	char 	name[256];
	int		ctimes;
	struct 	s_data *next;
}				t_data;

void	ft_ls(char *a);
t_data	*ft_addlink(t_data *list, char *str);
void	ft_print_list(t_data *list);
t_data	*ft_sort_list(t_data **begin, char *opt);
void	ft_swap_brick(t_data *tmp, t_data **begin);
t_data	*ft_addlink_stats(t_data *list, DIR *s_dir);

#endif
