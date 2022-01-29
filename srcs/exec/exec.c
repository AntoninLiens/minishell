/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:05:32 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/29 01:28:25 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_bin(char **cmd, t_mini *shell)
{
	char	*path;
	pid_t	pid;
	int		status;

	pid = fork();
	if (!pid)
	{
		if (!cmd)
			return (1);
		path = pathfinder(cmd[0], shell->env);
		if (!path || execve(path, cmd, shell->basic_env))
		{
			printf("minishell: %s: command not found\n", cmd[0]);
			exit(127);
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
	if (!ft_strncmp(cmd[0], "pwd", 4))
		shell->exit_status = pwd(shell->env, cmd);
	else if (!ft_strncmp(cmd[0], "env", 4))
		shell->exit_status = aff_env(shell->env, cmd);
	else if (!ft_strncmp(cmd[0], "exit", 5))
		shell->exit_status = mini_exit(shell, cmd);
	else if (!ft_strncmp(cmd[0], "export", 7))
		shell->exit_status = export(shell->env, cmd);
	else if (!ft_strncmp(cmd[0], "unset", 6))
		unset(shell->env, cmd[1]);
	else if (!ft_strncmp(cmd[0], "echo", 5))
		shell->exit_status = echo(cmd);
	else if (!ft_strncmp(cmd[0], "cd", 3))
		shell->exit_status = cd(shell, cmd);
	else
		return (0);
	return (1);
}
