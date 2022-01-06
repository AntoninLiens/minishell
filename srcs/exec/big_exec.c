/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:22:45 by aliens            #+#    #+#             */
/*   Updated: 2022/01/06 17:03:53 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int big_exec(t_mini *shell, int nb_cmds)
{
	t_cmd	*tmp;
	pid_t	pid;
	int		status;

    tmp = shell->cmd;
	(void)nb_cmds;
/*	if (nb_cmds > 1)
	{
		redir(tmp->str, shell, 0);
		tmp = tmp->next;
		while (tmp && tmp->next)
		{
			redir(tmp->str, shell, 0);
			tmp = tmp->next;
		}
	}
	if (tmp && !builts_in(shell, tmp->str))
	{
		if (exec_bin(shell->basic_env, tmp->str, shell))
			return (1);
	}
	return (0);*/
	while (tmp)
	{
		pid = fork();
		if (!pid)
		{
			if (tmp->fdin)
			{
				shell->fdin = open(tmp->fdin, O_RDONLY);
				dup2(shell->fdin, 0);
			}
			if (tmp->fdout)
			{
				if (tmp->append)
					shell->fdout = open(tmp->fdout, O_WRONLY | O_APPEND);
				else
					shell->fdout = open(tmp->fdout, O_WRONLY);
				dup2(shell->fdout, 1);
			}
			if (tmp && !builts_in(shell, tmp->str))
			{
				if (exec_bin(shell->basic_env, tmp->str, shell))
					return (1);
			}
			exit(shell->exit_status);
		}
		else
		{
			waitpid(pid, &status, 0);
			shell->exit_status = status;
		}
		tmp = tmp->next;
	}
	return (0);
}
