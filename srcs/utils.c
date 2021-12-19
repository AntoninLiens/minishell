/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@students.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:03:24 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/16 16:40:34 by zminhas          ###   ########.fr       */
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

int	check_operator(char *ans, t_mini *shell)
{
	char	**cmd;
	int		nb_cmd;
	int		i;

	nb_cmd = 1;
	while (ans[++i])
		if (ans[i] == '|')
			nb_cmd++;
	cmd = ft_split(ans, '|');
	i = -1;
	while (++i < nb_cmd)
		add_command(shell, cmd[i]);
}
