/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:22:45 by aliens            #+#    #+#             */
/*   Updated: 2022/01/03 16:02:47 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int big_exec(t_mini *shell, int nb_cmds)
{
    pid_t   pid;
	int		status;
	t_cmd	*tmp;

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
	if (tmp && !builts_in(shell, tmp->str))
	{
		pid = fork();
		if (!pid && exec_bin(shell->basic_env, tmp->str))	
			return (0);
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				shell->exit_status = WEXITSTATUS(status);
		}
	}
	return (0);
}
