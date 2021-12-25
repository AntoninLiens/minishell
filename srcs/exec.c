/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:05:32 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/25 16:23:20 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_bin(char **env, char *cmd)
{
	char	**arg;
	char	*path;

	if (!cmd)
		return (1);
	arg = ft_split(cmd, ' ');
	path = pathfinder(arg[0], env);
	if (execve(path, arg, env))
	{
		printf("minishell: command not found: %s\n", arg[0]);
		exit(1);
	}
	return (0);
}

int	builts_in(t_mini *shell, char *cmd)
{
	if (!cmd)
		return (0);
    if (!ft_strncmp(cmd, "pwd", 3))
        pwd(shell->env);
    else if (!ft_strncmp(cmd, "env", 3))
        env(shell->env);
    else if (!ft_strncmp(cmd, "exit", 4))
    	shell->exit = 1;
    else if (!ft_strncmp(cmd, "export", 6))
        export(shell->env, cmd);
    else if (!ft_strncmp(cmd, "unset", 5))
        unset(shell->env, cmd);
    else if (!ft_strncmp(cmd, "echo", 4))
        echo(cmd);
    else if (!ft_strncmp(cmd, "cd", 2))
        cd(shell);
	else
		return (0);
	return (1);
}
