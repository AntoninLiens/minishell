/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:20:04 by aliens            #+#    #+#             */
/*   Updated: 2021/12/23 17:32:11 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redir(char *cmd, t_mini *shell)
{
	int	fd[2];
	pid_t pid;

	pipe(fd);
	pid = fork();
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		if (!builts_in(shell, cmd))
			if (exec_bin(shell->basic_env, cmd))
				return ;
	}
}