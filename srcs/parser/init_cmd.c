/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:09:18 by aliens            #+#    #+#             */
/*   Updated: 2022/01/21 18:52:17 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init_first_cmd(t_mini *shell, char *command)
{
	shell->cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!shell->cmd)
		return (0);
	shell->cmd->end_parse_error = 0;
	shell->cmd->heredoc = 0;
	shell->cmd->append = 0;
	shell->cmd->s_quotes = 0;
	shell->cmd->d_quotes = 0;
	shell->cmd->prev = NULL;
	shell->cmd->next = NULL;
	command = quotes(command, shell->cmd);
	command = init_inoutfd(command, shell->cmd);
	if (shell->cmd->end_parse_error)
		return (0);
	shell->cmd->str = ft_split(command, ' ');
	return (1);
}

int	init_other_cmd(t_mini *shell, char *command)
{
	shell->cmd->next = (t_cmd *)malloc(sizeof(t_cmd));
	if (!shell->cmd->next)
		return (0);
	shell->cmd->next->end_parse_error = 0;
	shell->cmd->next->heredoc = 0;
	shell->cmd->next->append = 0;
	shell->cmd->s_quotes = 0;
	shell->cmd->d_quotes = 0;
	shell->cmd->next->prev = shell->cmd;
	shell->cmd->next->next = NULL;
	command = quotes(command, shell->cmd->next);
	command = init_inoutfd(command, shell->cmd->next);
	if (shell->cmd->next->end_parse_error)
		return (0);
	shell->cmd->next->str = ft_split(command, ' ');
	shell->cmd = shell->cmd->next;
	return (1);
}

int	add_command(t_mini *shell, char *command)
{
	if (!shell->cmd)
	{
		if(!init_first_cmd(shell, command))
			return (0);
	}
	else
	{
		if (!init_other_cmd(shell, command))
			return (0);
	}
	return (1);
}

int	init_cmd(t_mini *shell, char **cmd)
{
	int	i;
	
	if (!close_quotes(cmd))
	{
		printf("minishell: quotes not closed\n");
		return (0);
	}		
	i = -1;
	while(cmd[++i])
	{
		if (!add_command(shell, cmd[i]))
		{
			free_cmd(shell->cmd);
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

	shell->cmd = NULL;
	if (!ans[0])
		return (0);
	nb_cmd = 1;
	i = -1;
	while (ans[++i])
		if (ans[i] == '|')
			nb_cmd++;
	cmd = ft_split(ans, '|');
	if (!init_cmd(shell, cmd))
		return (0);
	return (nb_cmd);
}
