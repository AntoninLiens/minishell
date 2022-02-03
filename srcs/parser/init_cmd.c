/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:09:18 by aliens            #+#    #+#             */
/*   Updated: 2022/02/03 15:25:51 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_cmd_var(t_cmd *cmd, int type)
{
	cmd->end_parse_error = 0;
	cmd->heredoc = 0;
	cmd->append = 0;
	cmd->s_quotes = 0;
	cmd->d_quotes = 0;
	cmd->fdin = NULL;
	cmd->fdout = NULL;
	cmd->limit_string = NULL;
	if (!type)
		cmd->prev = NULL;
	cmd->next = NULL;
}

int	init_other_cmd(t_mini *shell, char *command)
{
	shell->cmd->next = (t_cmd *)malloc(sizeof(t_cmd));
	if (!shell->cmd->next)
		return (0);
	init_cmd_var(shell->cmd->next, 1);
	shell->cmd->next->prev = shell->cmd;
	command = init_inoutfd(command, shell->cmd->next);
	shell->cmd->next->str = ft_split(command, ' ');
	if (shell->cmd->next->end_parse_error)
		return (0);
	free(command);
	shell->cmd = shell->cmd->next;
	return (1);
}

int	add_command(t_mini *shell, char *command)
{
	if (!shell->cmd)
	{
		shell->cmd = (t_cmd *)malloc(sizeof(t_cmd));
		if (!shell->cmd)
			return (0);
		init_cmd_var(shell->cmd, 0);
		command = init_inoutfd(command, shell->cmd);
		shell->cmd->str = ft_split(command, ' ');
		if (shell->cmd->end_parse_error)
			return (0);
		free(command);
		return (1);
	}
	else
		if (!init_other_cmd(shell, command))
			return (0);
	return (1);
}

int	init_cmd(t_mini *shell, char **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (!add_command(shell, cmd[i]))
		{
			shell->cmd->end_parse_error = 1;
			return (0);
		}
	}
	lst_first(&shell->cmd);
	return (1);
}

int	check_operator(char *ans, t_mini *shell)
{
	char	**cmd;
	int		nb_cmd;
	int		i;

	if (!ans[0])
	{
		free(ans);
		return (0);
	}
	nb_cmd = 1;
	i = -1;
	ans = quotes(ans);
	if (!ans)
		return (0);
	while (ans[++i])
		if (ans[i] == -3)
			nb_cmd++;
	cmd = ft_split(ans, -3);
	if (!init_cmd(shell, cmd))
		nb_cmd = 0;
	free(ans);
	free(cmd);
	return (nb_cmd);
}
