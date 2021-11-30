/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:42:44 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 17:13:26 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*res;
	size_t	i;

	i = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)ft_calloc(sizeof(char), i + 1);
	if (!res)
	{
		if (s1)
			free((void *)s1);
		return (NULL);
	}
	ft_memcpy(res, s1, ft_strlen(s1));
	ft_memcpy(res + ft_strlen(s1), s2, ft_strlen(s2));
	free((void *)s1);
	return (res);
}

int	ft_isreturn(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*ft_strdup_gnl(char *save)
{
	size_t	i;
	char	*res;

	if (!save)
		return (NULL);
	res = (char *)ft_calloc(sizeof(char), ft_strlen(save) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (save[++i])
		res[i] = save[i];
	return (res);
}
