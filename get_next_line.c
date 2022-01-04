/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:25:00 by zessadqu          #+#    #+#             */
/*   Updated: 2022/01/04 23:53:15 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *str);

int	read_l(int fd);

char    *get_next_line(fd)
{
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
