/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:09:18 by aliens            #+#    #+#             */
/*   Updated: 2022/01/14 13:33:19 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	add_command(t_mini *shell, char *command)
{
	if (!shell->cmd)
	{
		shell->cmd = (t_cmd *)malloc(sizeof(t_cmd));
		if (!shell->cmd)
			return (1);
		shell->cmd->end_parse_error = 0;
		shell->cmd->heredoc = 0;
		shell->cmd->append = 0;
		shell->cmd->prev = NULL;
		shell->cmd->next = NULL;
		command = init_inoutfd(command, shell->cmd);
		if (shell->cmd->end_parse_error)
			return (1);
		shell->cmd->str = ft_split(command, ' ');
	}
	else
	{
		shell->cmd->next = (t_cmd *)malloc(sizeof(t_cmd));
		if (!shell->cmd->next)
			return (1);
		shell->cmd->next->end_parse_error = 0;
		shell->cmd->next->heredoc = 0;
		shell->cmd->next->append = 0;
		shell->cmd->next->prev = shell->cmd;
		shell->cmd->next->next = NULL;
		command = init_inoutfd(command, shell->cmd->next);
		if (shell->cmd->next->end_parse_error)
			return (1);
		shell->cmd->next->str = ft_split(command, ' ');
		shell->cmd = shell->cmd->next;
	}
	return (0);
}

int	check_operator(char *ans, t_mini *shell)
{
	char	**cmd;
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
		if (add_command(shell, cmd[i]))
		{
			free_cmd(shell->cmd);
			return (0);
		}
	}
	lst_first(&shell->cmd);
	return (nb_cmd);
}
