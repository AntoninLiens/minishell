/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:22:45 by aliens            #+#    #+#             */
/*   Updated: 2022/01/29 01:30:23 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	one_cmd_no_fork(t_mini *shell)
{
	if (shell->cmd && !shell->cmd->next)
	{
		if (!ft_strncmp(shell->cmd->str[0], "exit", 5)
			|| !ft_strncmp(shell->cmd->str[0], "cd", 3)
			|| !ft_strncmp(shell->cmd->str[0], "export", 7)
			|| !ft_strncmp(shell->cmd->str[0], "unset", 6))
		{
			builts_in(shell, shell->cmd->str);
			return (1);
		}
	}
	return (0);
}

int	big_exec(t_mini *shell)
{
	int		*pfd;
	int		i;

	if (one_cmd_no_fork(shell))
		return (0);
	pfd = (int *)malloc(sizeof(int) * (shell->nb_cmds) * 2);
	if (!pfd)
		return (0);
	i = -1;
	while (++i < shell->nb_cmds)
		pipe(pfd + i * 2);
	pipes(shell, pfd);
	return (0);
}
