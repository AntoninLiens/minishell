/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:42:44 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 17:37:42 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_end(int reader, char **line, char *save[FOPEN_MAX], int fd)
{
	*line = ft_linecpy(save[fd]);
	if (!(*line))
		return (-1);
	save[fd] = ft_savecpy(save[fd]);
	if (reader && !save[fd])
	{
		free(*line);
		return (-1);
	}
	if (!reader)
		return (0);
	return (1);
}

char	*ft_check_error(int fd, char **line)
{
	char	*buffer;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*ft_savecpy(char *save)
{
	char	*res;
	int		i;

	if (!save)
		return (NULL);
	i = -1;
	while (save[++i])
	{
		if (save[i] == '\n')
		{
			res = ft_strdup_gnl((char *)(save + i + 1));
			free((void *)save);
			return (res);
		}
	}
	free((void *)save);
	return (NULL);
}

char	*ft_linecpy(char *save)
{
	char	*res;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	res = (char *)ft_calloc(sizeof(char), i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		res[i] = save[i];
		i++;
	}
	return (res);
}

int	get_next_line(int fd, char **line)
{
	char			*buffer;
	long long int	reader;
	static char		*save[FOPEN_MAX];

	reader = 1;
	buffer = ft_check_error(fd, line);
	if (!buffer)
		return (-1);
	while (!ft_isreturn(save[fd]) && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[reader] = 0;
		save[fd] = ft_strjoin_gnl(save[fd], buffer);
		if (!save[fd])
			return (-1);
	}
	free(buffer);
	return (ft_end(reader, line, &save[fd], fd));
}
