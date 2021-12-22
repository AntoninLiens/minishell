/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:05:32 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/22 19:17:28 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_bin(char **env, t_cmd *cmd)
{
	pid_t	pid;
	char	**arg;
	char	*path;

	if (!cmd)
		return (1);
	arg = ft_split(cmd->str, ' ');
	path = pathfinder(arg[0], env);
	if (!path)
		return (0);
	pid = fork();
	if (!pid)
	{
		if (execve(path, arg, env))
		{
			printf("minishell: command not found: %s\n", arg[0]);
			return (0);
		}
		exit(1);
	}
	pid = waitpid(pid, 0, 0);
	return (0);
}

int	builts_in(t_mini *shell, t_cmd *cmd)
{
	if (!cmd)
		return (0);
    if (!ft_strncmp(cmd->str, "pwd", 3))
        pwd(shell->env);
    else if (!ft_strncmp(cmd->str, "env", 3))
        env(shell->env);
    else if (!ft_strncmp(cmd->str, "exit", 4))
    	shell->exit = 1;
    else if (!ft_strncmp(cmd->str, "export", 6))
        export(shell->env, cmd->str);
    else if (!ft_strncmp(cmd->str, "unset", 5))
        unset(shell->env, cmd->str);
    else if (!ft_strncmp(cmd->str, "echo", 4))
        echo(cmd->str);
    else if (!ft_strncmp(cmd->str, "cd", 2))
        cd(shell);
	else
		return (0);
	return (1);
}
