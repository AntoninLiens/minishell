/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/21 16:17:30 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	//shell->cmd = shell->cmd->next;
	return (1);
}

int	parser(char *ans, t_mini *shell)
{
	pid_t	pid;
	int		i;
	int		nb_cmds;

	i = -1;
	nb_cmds = check_operator(ans, shell);
	if (nb_cmds == 1)
	{
		if (!builts_in(shell))
		{
			pid = fork();
			if (!pid)
			{
				if (make_my_actions(shell, shell->basic_env))
					exit(1);
			}
			else
				waitpid(pid, 0, 0);
		}
		return (0);
	}
	while (++i < nb_cmds)
	{
		pid = fork();
		if (!pid)
		{
			if (begin_pipe(shell, i))
				return (1);
		}
		else 
			if (end_pipe(shell, i))
				return (1);
		waitpid(pid, 0, 0);
	}
	return (0);
}
