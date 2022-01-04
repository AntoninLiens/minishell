/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:03:24 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/04 18:46:19 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*pathfinder(char *ans, char **env)
{
	char	**paths;
	char	*part_path;
	char	*path;
	int		i;

	if (!access(ans, F_OK))
		return (ans);
	i = -1;
	while (!ft_strnstr(env[++i], "PATH", 4))
		;
	paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, ans);
		free(part_path);
		if (!access(path, F_OK))
			return (path);
	}
	if (ans)
		printf("minishell: command not found: %s\n", ans);
	exit(1);
}

void    lst_first(t_cmd **list)
{
    if (list && *list)
        while ((*list)->prev)
            *list = (*list)->prev;
}

void    lst_last(t_cmd **list)
{
    if (list && *list)
        while ((*list)->next)
            *list = (*list)->next;
}

char	*ft_strjoin_mini(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	j = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * j);
	if (!res)
		return (NULL);
	res[j] = 0;
	i = -1;
	while (s1 && s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2 && s2[++j])
		res[i + j] = s2[j];
	return (res);
}

char	*get_file_name(char *str)
{
	char	*name;
	int		i;

	if (!str)
		return (NULL);
	name = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!name)
		return (NULL);
	i = -1;
	while (str[++i])
		name[i] = str[i];
	return (name); 
}
