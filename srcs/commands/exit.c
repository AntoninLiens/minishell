/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:36:01 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/31 10:54:49 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	mini_exit(t_mini *shell, char **cmd)
{
	int	i;

	if (cmd[2])
	{
		printf("minishell: exit: too many argument\n");
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
		printf("minishell: exit: Illegal number: %s\n", cmd[1]);
		return (2);
	}
	shell->exit = 1;
	return (ft_atoi(cmd[1]));
}
