/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:09:18 by aliens            #+#    #+#             */
/*   Updated: 2022/01/05 14:21:32 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_command(t_mini *shell, char **command)
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

int	check_operator(char *ans, t_mini *shell)
{
	char	**cmd;
	char	**arg;
	int		nb_cmd;
	int		i;

	shell->cmd = NULL;
	if (!ans[0])
		return (0);
	nb_cmd = 1;
	i = -1;
	while (ans[++i])
		if (ans[i] == '|')
			nb_cmd++;
	cmd = ft_split(ans, '|');
	i = -1;
	while(cmd[++i])
	{
		arg = ft_split(cmd[i],  ' ');
		add_command(shell, arg);
	}
	lst_first(&shell->cmd);
	return (nb_cmd);
}
