/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utiles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:25:00 by zessadqu          #+#    #+#             */
/*   Updated: 2021/12/31 18:25:05 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int check_line(char *str);

int ft_strlen(const char *str);

char    *get_next_line(fd)
{
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int check_line(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(str[i] == '\n')
            rerurn (i);
        i++;
    }
    return (-1);
}
