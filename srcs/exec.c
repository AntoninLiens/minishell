/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:05:32 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/21 17:47:46 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_bin(t_mini *shell, char **env)
{
	pid_t	pid;
	char	**cmd;
	char	*path;

	if (!shell->cmd)
		return (1);
	cmd = ft_split(shell->cmd->str, ' ');
	path = pathfinder(cmd[0], env);
	if (!path)
		return (1);
	pid = fork();
	if (!pid)
	{
		if (execve(path, cmd, env))
		{
			printf("minishell: command not found: %s\n", cmd[0]);
			return (1);
		}
	}
	else
		waitpid(pid, 0, 0);
	shell->cmd = shell->cmd->next;
	return (0);
}

int	builts_in(t_mini *shell)
{
	if (!shell->cmd)
		return (0);
    if (!ft_strncmp(shell->cmd->str, "pwd", 3))
        pwd(shell->env);
    else if (!ft_strncmp(shell->cmd->str, "env", 3))
        env(shell->env);
    else if (!ft_strncmp(shell->cmd->str, "exit", 4))
    	shell->exit = 1;
    else if (!ft_strncmp(shell->cmd->str, "export", 6))
        export(shell->env, shell->cmd->str);
    else if (!ft_strncmp(shell->cmd->str, "unset", 5))
        unset(shell->env, shell->cmd->str);
    else if (!ft_strncmp(shell->cmd->str, "echo", 4))
        echo(shell->cmd->str);
    else if (!ft_strncmp(shell->cmd->str, "cd", 2))
        cd(shell);
	else
		return (0);
	shell->cmd = shell->cmd->next;
	return (1);
}
