/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:22:45 by aliens            #+#    #+#             */
/*   Updated: 2022/01/10 18:20:30 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int big_exec(t_mini *shell)
{
	t_cmd	*tmp;
	pid_t	pid;
	int		status;

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
	while (tmp)
	{
		pid = fork();
		if (!pid)
		{
			mini_inout(shell, tmp);
			if (!tmp->str[0])
				return (0);
			if (tmp && !builts_in(shell, tmp->str))
			{
				if (exec_bin(tmp->str, shell))
					return (1);
			}
			exit(shell->exit_status);
		}
		else
		{
			waitpid(pid, &status, 0);
			shell->exit_status = status;
		}
		tmp = tmp->next;
	}
	return (0);
}
