/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/30 17:17:52 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parser(char *ans, t_mini *shell)
{
	pid_t	pid;
	t_cmd	*tmp;
	int		nb_cmds;
	int		i;

	nb_cmds = check_operator(ans, shell);
	while (shell->cmd && shell->cmd->next)
	{
		i = -1;
		while (shell->cmd->str[++i])
			printf("%d : %s\n", i, shell->cmd->str[i]);
		printf("------------------------\n");
		shell->cmd = shell->cmd->next;
	}
	lst_first(&shell->cmd);
	//replace_env_variable(shell);
	if (!nb_cmds)
		return (0);
	tmp = shell->cmd;
	if (nb_cmds > 1)
	{
		redir(tmp->str, shell, 0);
		tmp = tmp->next;
		while (tmp && tmp->next)
		{
			redir(tmp->str, shell, 0);
			tmp = tmp->next;
		}
	}
	if (!tmp)
		return (0);
	if (!builts_in(shell, tmp->str))
	{
		pid = fork();
		if (!pid && exec_bin(shell->basic_env, tmp->str))	
			return (0);
		else
			waitpid(pid, 0, 0);
	}
	return (0);
}
