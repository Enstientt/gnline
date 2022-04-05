/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:53:28 by zessadqu          #+#    #+#             */
/*   Updated: 2022/04/04 13:35:52 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_line(int fd)
{
	char	*buff;
	char	*hold;
	int		x;

	hold = ft_calloc(1, sizeof(char));
	if (!hold)
		return (0);
	x = 1;
	while (x > 0 && new_line(hold) == -1)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (0);
		buff[BUFFER_SIZE] = 0;
		x = read(fd, buff, BUFFER_SIZE);
		hold = ft_strjoin(hold, buff);
	}
	return (hold);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*buff;
	char		*hold;

	if (read(fd, NULL, 0) < 0)
		return (0);
	buff = read_line(fd);
	if (remain)
	{
		buff = ft_strjoin(remain, buff);
		remain = 0;
	}
	if (new_line(buff) != -1)
	{
		remain = ft_strdup(buff + new_line(buff) + 1);
		hold = ft_substr(buff, 0, new_line(buff) + 1);
		return (hold);
	}
	if (!(*buff))
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}
