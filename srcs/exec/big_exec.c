/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:22:45 by aliens            #+#    #+#             */
/*   Updated: 2022/01/17 16:06:08 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	one_cmd_no_fork(t_mini *shell)
{
	if (shell->cmd && !shell->cmd->next)
	{
		if (!ft_strncmp(shell->cmd->str[0], "exit", 4)
		|| !ft_strncmp(shell->cmd->str[0], "cd", 2)
		|| !ft_strncmp(shell->cmd->str[0], "export", 6)
		|| !ft_strncmp(shell->cmd->str[0], "unset", 5))
		{
			builts_in(shell, shell->cmd->str);
			return (1);
		}
	}
	return (0);
}

int big_exec(t_mini *shell)
{
	int		*pfd;
	int		i;

	if (one_cmd_no_fork(shell))
		return (0);
	pfd = (int *)malloc(sizeof(int) * (shell->nb_cmds - 1) * 2);
	if (!pfd)
		return (0);
	i = -1;
	while (++i < shell->nb_cmds - 1)
		pipe(pfd + i * 2);
	pipes(shell, pfd);
	// waitpid(pid, 0, 0);
	// if (WIFEXITED(status))
	// 	shell->exit_status = WEXITSTATUS(status);
	// i = -1;
	// while (++i < (shell->nb_cmds - 1) * 2)
	// 	close(pfd[i]);
	return (0);
}

