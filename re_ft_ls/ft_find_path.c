/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 18:12:26 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/11 18:12:26 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char    **ft_find_path(int ac, char **av)
{
    char **path;
    int j;
    int i;

    j = 1;
    i = 1;
    while (av[j] != '\0')
    {
        if (av[j][0] == '-')
            i++;
        j++;
    }
    j = i;
    while (av[j] != '\0')
        j++;
    path = (char**)malloc(sizeof(char*) * j + 1);
    if (path == 0)
        return (0);
    j = 0;
    while (av[i] != '\0')
    {
        path[j] = av[i];
        i++;
        j++;
    }
    path[j] = '\0';
    j = 0;
    return (path);
}
