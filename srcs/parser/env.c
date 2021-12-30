/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:10:39 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/30 18:18:12 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	replace_env_variable(t_mini *shell)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;
	char	*perm;
	char	*name;
	t_cmd	*cmd;

	perm = NULL;
	tmp = NULL;
	cmd = shell->cmd;
	while(cmd)
	{
		i = -1;
		while (cmd->str[++i])
		{
			j = -1;
			while (cmd->str[i][++j])
			{
				if (cmd->str[i][j] == '$')
				{
					perm = ft_substr(cmd->str[i], 0, j);
					j++;
					k = 0;
					while (cmd->str[i][j + k] && cmd->str[i][j + k] != '$')
						k++;
					name = ft_substr(cmd->str[i], j, k);
					tmp = get_env_val(shell->env, name);
					perm = ft_strjoin(perm, tmp);
					cmd->str[i] = ft_strjoin(perm,\
						ft_substr(cmd->str[i], j + k, ft_strlen(cmd->str[i])));
					j = -1;
				}
			}
		}
		cmd = cmd->next;
	}
}

char    *get_env_val(t_env *env, char *name)
{
	t_env	*tmp;
	char	*res;
	int		i;

	tmp = env;
	while (tmp)
	{
		i = -1;
		while (tmp->str[++i] != '=')
			;
		res = ft_substr(tmp->str, 0, i);
		if (!ft_strncmp(name, res, ft_strlen(res) + 1))
		{
			free(res);
			return (ft_substr(tmp->str, i + 1, ft_strlen(tmp->str) - i));
		}
		free(res);
		tmp = tmp->next;
	}
	return (NULL);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env->next)
	{
		tmp = env;
		env = tmp->next;
		free(tmp);
	}
	free(env);
}
