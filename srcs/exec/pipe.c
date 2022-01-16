/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:49:51 by aliens            #+#    #+#             */
/*   Updated: 2022/01/16 18:00:51 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pipes(t_mini *shell, int *pfd)
{
	pid_t	pid;
	int		i;
	int		j;
	t_cmd	*tmp;

	i = 0;
    tmp = shell->cmd;
	while (tmp)
	{
		pid = fork();
		if (!pid)
		{
			set_sig_cmd_in(tmp);
			if (tmp->prev && !tmp->heredoc)
				dup2(pfd[i - 2], 0);
			if (tmp->prev && tmp->heredoc)
				dup2(pfd[i - 2], mini_heredoc(tmp));
			if (tmp->heredoc)
				mini_heredoc(tmp);
			if (tmp->next)
				dup2(pfd[i + 1], 1);
			if (!tmp->str[0])
				exit(0);
			j = -1;
			while (++j < (shell->nb_cmds - 1) * 2)
				close(pfd[j]);
			mini_inout(shell, tmp);
			if (tmp && !builts_in(shell, tmp->str))
			{
				if (exec_bin(tmp->str, shell))
					return (1);
			}
			exit(shell->exit_status);
		}
		tmp = tmp->next;
		i += 2;
	}
	return (pid);
}