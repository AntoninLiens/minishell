/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:20:04 by aliens            #+#    #+#             */
/*   Updated: 2022/01/06 18:01:05 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redir(char **cmd, t_mini *shell, int b2o)
{
	pid_t pid;

	if (b2o)
		return ;
	pipe(shell->pfd);
	pid = fork();
	if (pid)
	{
		close(shell->pfd[1]);
		dup2(shell->pfd[0], b2o);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(shell->pfd[0]);
		dup2(shell->pfd[1], 1);
		if (!builts_in(shell, cmd))
			if (exec_bin(shell->basic_env, cmd, shell))
				return ;
	}
}