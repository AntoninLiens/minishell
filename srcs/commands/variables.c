/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:04:02 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/29 02:09:55 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**sort_env(char **export)
{
	char	*tmp;
	int		i;
	int		j;

	j = -1;
	while (export[++j])
		;
	while (--j)
	{
		i = -1;
		while (export[++i + 1])
		{
			if (ft_strncmp(export[i], export[i + 1], ft_strlen(export[i])) > 0)
			{
				tmp = export[i];
				export[i] = export[i + 1];
				export[i + 1] = tmp;
			}
		}
	}
	return (export);
}

int	norm_2(char **export, t_env *tmp)
{
	int	i;

	i = -1;
	while (tmp)
	{
		i++;
		export[i] = ft_strdup(tmp->str);
		if (!export[i])
		{
			free_double_char(export);
			return (-1);
		}
		tmp = tmp->next;
	}
	return (i);
}

int	export_no_arg(t_env *env)
{
	char	**export;
	t_env	*tmp;
	int		i;

	tmp = env;
	export = (char **)malloc(sizeof(char *) * (ft_lstsize((t_list *)tmp) + 1));
	if (!export)
		return (-1);
	i = norm_2(export, tmp);
	export[i + 1] = NULL;
	export = sort_env(export);
	i = -1;
	while (export[++i])
		printf("declare -x %s\n", export[i]);
	free_double_char(export);
	return (0);
}

int	export(t_env *env, char **cmd)
{
	t_env	*tmp;

	if (!cmd[1])
		return (export_no_arg(env));
	tmp = env;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_env *)malloc(sizeof(t_env));
	if (!tmp->next)
		return (-1);
	tmp->next->str = ft_strdup(cmd[1]);
	tmp->next->next = NULL;
	return (0);
}

void	unset(t_env *env, char *name)
{
	t_env	*tmp;
	t_env	*tmp2;

	tmp = env;
	if (!ft_strncmp(tmp->str, name, ft_strlen(name)))
	{
		env = env->next;
		free(tmp->str);
		free(tmp);
		return ;
	}
	while (tmp->next)
	{
		if (!ft_strncmp(tmp->next->str, name, ft_strlen(name)))
		{
			tmp2 = tmp->next->next;
			free(tmp->next->str);
			free(tmp->next);
			tmp->next = tmp2;
			return ;
		}
		tmp = tmp->next;
	}
}
