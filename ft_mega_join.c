/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mega_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:57:57 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/05 15:58:01 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char	*ft_mega_join(char *path, char *backslash, char *name)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin(path, backslash);
	tmp2 = ft_strjoin(tmp, name);
	free(tmp);
	return (tmp2);
}