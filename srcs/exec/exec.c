/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:05:32 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/30 17:12:05 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_bin(char **env, char **cmd)
{
	char	*path;

	if (!cmd)
		return (1);
	path = pathfinder(cmd[0], env);
	if (execve(path, cmd, env))
	{
		printf("minishell: command not found: %s\n", cmd[0]);
		exit(1);
	}
	return (0);
}

int	builts_in(t_mini *shell, char **cmd)
{
	if (!cmd)
		return (0);
    if (!ft_strncmp(cmd[0], "pwd", 3))
        pwd(shell->env);
    else if (!ft_strncmp(cmd[0], "env", 3))
        env(shell->env);
    else if (!ft_strncmp(cmd[0], "exit", 4))
    	shell->exit = 1;
    else if (!ft_strncmp(cmd[0], "export", 6))
        export(shell->env, cmd[0]);
    else if (!ft_strncmp(cmd[0], "unset", 5))
        unset(shell->env, cmd[0]);
    else if (!ft_strncmp(cmd[0], "echo", 4))
        echo(cmd);
    else if (!ft_strncmp(cmd[0], "cd", 2))
        cd(shell, cmd);
	else
		return (0);
	return (1);
}
