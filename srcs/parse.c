/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/20 17:19:24 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	builts_in(char *ans, t_mini *shell)
{
	char	**cmds;

	if (!ans[0])
        return (1);
    cmds = ft_split(ans, ' ');
    if (!ft_strncmp(cmds[0], "pwd", 4))
        pwd(shell->env);
    else if (!ft_strncmp(cmds[0], "env", 4))
        env(shell->env);
    else if (!ft_strncmp(cmds[0], "exit", 5))
    	shell->exit = 1;
    else if (!ft_strncmp(cmds[0], "export", 7))
        export(shell->env, cmds[1]);
    else if (!ft_strncmp(cmds[0], "unset", 6))
        unset(shell->env, cmds[1]);
    else if (!ft_strncmp(cmds[0], "echo", 5))
        echo(cmds);
    else if (!ft_strncmp(cmds[0], "cd", 3))
        cd(cmds[1], shell);
	else
		return (0);
	return (1);
}

int	parser(char *ans, t_mini *shell)
{
	pid_t	pid;
	int		i;
	int		nb_cmds;

	i = -1;
	nb_cmds = check_operator(ans, shell);
	shell->pipes = malloc_pipes(nb_cmds, shell);
	if (!shell->pipes)
		return (1);
	if (nb_cmds == 1)
	{
		pid = fork();
		if (!pid)
		{
			if (!builts_in(ans, shell))
			{
				if (make_my_actions(shell->answer, shell->basic_env))
					exit(1);
			}
			else
				exit(1);
		}
		else
			waitpid(pid, 0, 0);
		return (0);
	}
	while (++i < nb_cmds)
	{
		pid = fork();
		if (!pid)
		{
			if (begin_pipe(ans, shell, i))
				return (1);
		}
		else 
			if (end_pipe(ans, shell, i))
				return (1);
		waitpid(pid, 0, 0);
	}
	return (0);
}
