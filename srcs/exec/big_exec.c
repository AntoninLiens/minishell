/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:22:45 by aliens            #+#    #+#             */
/*   Updated: 2022/01/06 18:06:01 by aliens           ###   ########.fr       */
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
	}*/
	while (tmp)
	{
		pid = fork();
		if (!pid)
		{
			mini_inout(shell, tmp);
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
