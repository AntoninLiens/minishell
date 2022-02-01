/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:36:01 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/01 16:46:12 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	mini_exit(t_mini *shell, char **cmd)
{
	int	i;

	if (cmd[2])
	{
		ft_putstr_fd("minishell: exit: too many argument\n", STDERR_FILENO);
		return (2);
	}
	if (!cmd[1])
	{
		shell->exit = 1;
		return (0);
	}
	i = 0;
	while (cmd[1][i] && (ft_isdigit(cmd[1][i]) || cmd[1][i] == '-'))
		i++;
	if (cmd[1][i])
	{
		ft_putstr_fd("minishell: exit: Illegal number: ", STDERR_FILENO);
		ft_putstr_fd(cmd[1], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		return (2);
	}
	shell->exit = 1;
	return (ft_atoi(cmd[1]));
}
