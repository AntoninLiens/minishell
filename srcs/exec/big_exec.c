/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:22:45 by aliens            #+#    #+#             */
/*   Updated: 2022/01/13 14:57:23 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int big_exec(t_mini *shell)
{
	pid_t	pid;
	t_cmd	*tmp;
	int		*pfd;
	int		status;
	int		i;
	int		j;

    tmp = shell->cmd;
	if (tmp && !tmp->next)
	{
		if (!ft_strncmp(tmp->str[0], "exit", 4)
		|| !ft_strncmp(tmp->str[0], "cd", 2)
		|| !ft_strncmp(tmp->str[0], "export", 6)
		|| !ft_strncmp(tmp->str[0], "unset", 5))
		{
			builts_in(shell, tmp->str);
			return (0);
		}
	}
	pfd = (int *)malloc(sizeof(int) * (shell->nb_cmds - 1) * 2);
	if (!pfd)
		return (0);
	i = -1;
	while (++i < shell->nb_cmds - 1)
		pipe(pfd + i * 2);
	i = 0;
	while (tmp)
	{
		pid = fork();
		if (!pid)
		{
			mini_inout(shell, tmp);
			if (!tmp->str[0])
				return (0);
			if (tmp->prev)
				dup2(pfd[i - 2], 0);
			if (tmp->next)
				dup2(pfd[i + 1], 1);
			j = -1;
			while (++j < (shell->nb_cmds - 1) * 2)
				close(pfd[j]);
			if (tmp && !builts_in(shell, tmp->str))
			{
				if (exec_bin(tmp->str, shell))
					return (1);
			}
			exit(shell->exit_status);
		}
		tmp = tmp->next;
		i += 2;
	}
	j = -1;
	while (++j < (shell->nb_cmds - 1) * 2)
		close(pfd[j]);
	waitpid(pid, &status, 0);
	shell->exit_status = status;
	return (0);
}
