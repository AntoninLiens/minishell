/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/31 16:03:08 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parser(char *ans, t_mini *shell)
{
	pid_t	pid;
	t_cmd	*tmp;
	int		status;
	int		nb_cmds;

	nb_cmds = check_operator(ans, shell);
	lst_first(&shell->cmd);
	replace_env_variable(shell);
	if (!nb_cmds)
		return (0);
	tmp = shell->cmd;
	if (nb_cmds > 1)
	{
		redir(tmp->str, shell, 0);
		tmp = tmp->next;
		while (tmp && tmp->next)
		{
			redir(tmp->str, shell, 0);
			tmp = tmp->next;
		}
	}
	if (!tmp)
		return (0);
	if (!builts_in(shell, tmp->str))
	{
		pid = fork();
		if (!pid && exec_bin(shell->basic_env, tmp->str))	
			return (0);
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				shell->exit_status = WEXITSTATUS(status);
		}
	}
	return (0);
}
