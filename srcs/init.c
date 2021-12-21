/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:44:07 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/21 17:06:32 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_command(t_mini *shell, char *command)
{
	if (!shell->cmd)
	{
		shell->cmd = (t_cmd *)malloc(sizeof(t_cmd));
		if (!shell->cmd)
			shell->exit = 1;
		shell->cmd->str = command;
		shell->cmd->prev = NULL;
		shell->cmd->next = NULL;
	}
	else
	{
		shell->cmd->next = (t_cmd *)malloc(sizeof(t_cmd));
		if (!shell->cmd->next)
			shell->exit = 1;
		shell->cmd->next->str = command;
		shell->cmd->next->prev = shell->cmd;
		shell->cmd->next->next = NULL;
		shell->cmd = shell->cmd->next;
	}
}

int init_env(t_mini *shell, char **basic_env)
{
	t_env	*tmp;
	int		i;

	shell->env = (t_env *)malloc(sizeof(t_env));
	if (!shell->env)
		return (1);
	tmp = shell->env;
	i = -1;
	while (basic_env[++i])
	{
		tmp->str = ft_strdup(basic_env[i]);
		if (basic_env[i + 1])
		{
			tmp->next = (t_env *)malloc(sizeof(t_env));
			if (!tmp->next)
			{
				free_env(shell->env);
				return (1);
			}
			tmp = tmp->next;
		}
		else
			tmp->next = NULL;
	}
	return (0);
}