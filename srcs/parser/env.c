/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@students.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:10:39 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/28 14:40:57 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_env_var(t_cmd *cmd, int i, t_mini *shell)
{
	char	*name;
	char	*perm;
	char	*tmp;
	int		j;
	int		k;

	name = NULL;
	perm = NULL;
	tmp = NULL;
	j = -1;
	while (cmd->str[i][++j])
	{
		if (cmd->str[i][j] == -2)
		{
			perm = ft_substr(cmd->str[i], 0, j);
			j++;
			k = 0;
			while (cmd->str[i][j + k] && cmd->str[i][j + k] != -2 \
			&& cmd->str[i][j + k] != '\'' && cmd->str[i][j + k] != '\"')
				k++;
			name = ft_substr(cmd->str[i], j, k);
			if (!ft_strncmp(name, "?", 2))
				tmp = ft_itoa(shell->exit_status);
			else
				tmp = get_env_val(shell->env, name);
			free(name);
			perm = ft_strjoin_gnl(perm, tmp);
			free(tmp);
			name = ft_substr(cmd->str[i], j + k, \
				ft_strlen(cmd->str[i]) - j - k);
			free(cmd->str[i]);
			cmd->str[i] = ft_strjoin_gnl(perm, name);
			free(name);
			j = -1;
		}
		else if (cmd->str[i][j] == -1)
			cmd->str[i][j] = ' ';
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

void	replace_env_variable(t_mini *shell)
{
	t_cmd	*cmd;
	int		i;

	cmd = shell->cmd;
	while(cmd)
	{
		i = -1;
		while (cmd->str[++i])
			get_env_var(cmd, i, shell);
		cmd = cmd->next;
	}
}
