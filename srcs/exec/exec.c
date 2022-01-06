/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:05:32 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/06 18:00:23 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_bin(char **env, char **cmd, t_mini *shell)
{
	char	*path;
	pid_t	pid;
	int		status;
	int		error;

	errno = 0;
	pid = fork();
	if (!pid)
	{
		if (!cmd)
			return (1);
		path = pathfinder(cmd[0], env);
		if (execve(path, cmd, env))
		{
			error = errno;
			printf("minishell: %s: %s\n", cmd[0], strerror(error));
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			shell->exit_status = WEXITSTATUS(status);
	}
	return (0);
}

int	builts_in(t_mini *shell, char **cmd)
{
	if (!cmd)
		return (0);
    if (!ft_strncmp(cmd[0], "pwd", 3))
        shell->exit_status = pwd(shell->env, cmd);
    else if (!ft_strncmp(cmd[0], "env", 3))
    	shell->exit_status = env(shell->env, cmd);
    else if (!ft_strncmp(cmd[0], "exit", 4))
    	shell->exit = 1;
    else if (!ft_strncmp(cmd[0], "export", 6))
        shell->exit_status = export(shell->env, cmd);
    else if (!ft_strncmp(cmd[0], "unset", 5))
        unset(shell->env, cmd[1]);
    else if (!ft_strncmp(cmd[0], "echo", 4))
        shell->exit_status = echo(cmd);
    else if (!ft_strncmp(cmd[0], "cd", 2))
        shell->exit_status = cd(shell, cmd);
	else
		return (0);
	return (1);
}

void	mini_inout(t_mini *shell, t_cmd *cmd)
{
	if (cmd->fdin)
	{
		shell->fdin = open(cmd->fdin, O_RDONLY);
		dup2(shell->fdin, 0);
	}
	if (cmd->fdout)
	{
		if (cmd->append)
			shell->fdout = open(cmd->fdout, O_WRONLY | O_APPEND);
		else
			shell->fdout = open(cmd->fdout, O_WRONLY);
		dup2(shell->fdout, 1);
	}
}