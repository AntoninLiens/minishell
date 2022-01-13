/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:03:24 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/13 18:07:57 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*pathfinder(char *ans, t_env *env)
{
	char	**paths;
	char	*part_path;
	char	*path;
	t_env	*tmp;
	int		i;

	if (!access(ans, F_OK))
		return (ans);
	tmp = env;
	while (!ft_strnstr(tmp->str, "PATH", 4))
		tmp = tmp->next;
	paths = ft_split(tmp->str + 5, ':');
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, ans);
		free(part_path);
		if (!access(path, F_OK))
			return (path);
	}
	free(path);
	return (NULL);
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
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '>' && str[i] != '<')
		i++;
	name = (char *)malloc(sizeof(char) * (i + 1));
	if (!name)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '>' && str[i] != '<')
	{
		name[i] = str[i];
		i++;
	}
	name[i] = 0;
	return (name); 
}
