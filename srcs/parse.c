/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/23 17:43:24 by aliens           ###   ########.fr       */
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
	pid_t	pid;
	t_cmd	*tmp;
	int		nb_cmds;

	nb_cmds = check_operator(ans, shell);
	if (!nb_cmds)
		return (0);
	tmp = shell->cmd;
	if (nb_cmds == 1)
	{
		if (!builts_in(shell, tmp->str))
		{
			pid = fork();
			if (!pid && exec_bin(shell->basic_env, tmp->str))	
				return (1);
			else
				waitpid(pid, 0, 0);
		}
		return (0);
	}
	redir(tmp->str, shell);
	tmp = tmp->next;
	while (tmp && tmp->next)
	{
		redir(tmp->str, shell);
		tmp = tmp->next;
	}
	if (!tmp)
		return (0);
	// faire appelle à redir avec une option qui skip les redir; last cmd->STDOUT
	if (!builts_in(shell, tmp->str))
	{
		pid = fork();
		if (!pid && exec_bin(shell->basic_env, tmp->str))	
			return (1);
		else
			waitpid(pid, 0, 0);
	}
	return (0);
}
