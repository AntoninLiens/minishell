/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@students.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/22 19:05:30 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_operator(char *ans, t_mini *shell)
{
	char	**cmd;
	int		nb_cmd;
	int		i;

	nb_cmd = 1;
	i = -1;
	while (ans[++i])
		if (ans[i] == '|')
			nb_cmd++;
	cmd = ft_split(ans, '|');
	i = -1;
	shell->cmd = NULL;
	if (!ans[0])
		return (0);
	while (++i < nb_cmd)
		add_command(shell, cmd[i]);
	lst_first(&shell->cmd);
	return (nb_cmd);
}

int	parser(char *ans, t_mini *shell)
{
	t_cmd	*tmp;
	pid_t	pid;
	int		nb_cmds;
	int		i;

	nb_cmds = check_operator(ans, shell);
	if (!nb_cmds)
		return (0);
	else if (nb_cmds == 1)
	{
		if (!builts_in(shell, shell->cmd))
			if (exec_bin(shell->basic_env, shell->cmd))
				return (1);
		return (0);
	}
	malloc_pipes(nb_cmds - 1, shell);
	if (!shell->pipes)
		return (1);
	i = 0;
	tmp = shell->cmd;
	while (tmp)
	{
		pid = fork();
		if (!pid)
		{
			if (common_pipes(shell, tmp, shell->pipes[i]))
				return (1);
		}
		else
		{
			if (end_pipe(shell, tmp, shell->pipes[i]))
				return (1);
			tmp = tmp->next;
			i++;
		}
		waitpid(pid, 0, 0);
	}
	
	return (0);
}
