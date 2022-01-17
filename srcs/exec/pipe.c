/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:49:51 by aliens            #+#    #+#             */
/*   Updated: 2022/01/17 16:12:38 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pipes(t_mini *shell, int *pfd)
{
	pid_t	pid;
	int		i;
	int		j;
	t_cmd	*tmp;
	int		status;

	i = 0;
    tmp = shell->cmd;
	while (tmp)
	{
		set_sig_cmd_out(shell->cmd);
		pid = fork();
		if (!pid && set_sig_cmd_in(tmp))
		{
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
	close_my_pipes(pfd, (shell->nb_cmds - 1) * 2);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->exit_status = WEXITSTATUS(status);
	return (0);
}

void	close_my_pipes(int *pfd, int size)
{
	int i;

	i = -1;
	while (++i < size)
		close(pfd[i]);
}
