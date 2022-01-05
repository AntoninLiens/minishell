/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:09:18 by aliens            #+#    #+#             */
/*   Updated: 2022/01/05 15:53:38 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_command(t_mini *shell, char *command)
{
	int		i;
	
	if (!shell->cmd)
	{
		shell->cmd = (t_cmd *)malloc(sizeof(t_cmd));
		if (!shell->cmd)
			shell->exit = 1;
		shell->cmd->prev = NULL;
		shell->cmd->next = NULL;
		shell->cmd->heredoc = 0;
		command = init_inoutfd(command, shell->cmd);
		shell->cmd->str = ft_split(command, ' ');
		i = -1;
		while (shell->cmd->str[++i])
			printf("%s\n", shell->cmd->str[i]);
	}
	else
	{
		shell->cmd->next = (t_cmd *)malloc(sizeof(t_cmd));
		if (!shell->cmd->next)
			shell->exit = 1;
		shell->cmd->next->prev = shell->cmd;
		shell->cmd->next->next = NULL;
		shell->cmd->heredoc = 0;
		command = init_inoutfd(command, shell->cmd);
		shell->cmd = shell->cmd->next;
		shell->cmd->next->str = ft_split(command, ' ');
	}
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
		add_command(shell, cmd[i]);
	lst_first(&shell->cmd);
	return (nb_cmd);
}
