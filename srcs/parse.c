/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/21 18:01:32 by ctirions         ###   ########.fr       */
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
	return (nb_cmd);
}

int	parser(char *ans, t_mini *shell)
{
	int		i;
	int		nb_cmds;

	i = -1;
	pipe(shell->pipes[0]);
	pipe(shell->pipes[1]);
	nb_cmds = check_operator(ans, shell);
	if (nb_cmds == 1)
	{
		if (!builts_in(shell))
			if (exec_bin(shell, shell->basic_env))
				return (1);
		return (0);
	}
	while (++i < nb_cmds)
	{
		if (i + 1 == nb_cmds && end_pipe(shell, i))
			return (1);
		else if (common_pipes(shell, i))
			return (1);
	}
	return (0);
}
