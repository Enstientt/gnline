/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:11:45 by zessadqu          #+#    #+#             */
/*   Updated: 2022/03/03 10:02:14 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*remain[1024];
	char		*buff;
	char		*hold;

	if (read(fd, NULL, 0) < 0)
		return (0);
	buff = read_line(fd);
	if (remain[fd])
	{
		buff = ft_strjoin(remain[fd], buff);
		remain[fd] = 0;
	}
	if (new_line(buff) != -1)
	{
		remain[fd] = ft_strdup(buff + new_line(buff) + 1);
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
/*int main()
{
	int fd[3];
	fd[0]  = open("get_next_line_bonus.h", O_RDWR);
	fd[1]  = open("get_next_line.c", O_RDWR);
	fd[2]  = open("get_next_line.h", O_RDWR);
	char *str[3];
	int i = 0;
	while (i < 3)
	{
		str[i] = get_next_line(fd[i]);
		while (str[i])
		{
			printf("%s", str[i]);
			str[i] = get_next_line(fd[i]);
		}
		i++;
	}
	
}*/