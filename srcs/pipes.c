/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:20:04 by aliens            #+#    #+#             */
/*   Updated: 2021/12/21 18:21:40 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	common_pipes(t_mini *shell, int i)
{
	close(shell->pipes[i % 2][0]);
	dup2(shell->pipes[i % 2][1], STDOUT_FILENO);
	if (i)
		dup2(shell->pipes[(i - 1) % 2][0], STDIN_FILENO);
	if (!builts_in(shell))
		if (exec_bin(shell, shell->basic_env))
			return (1);
	return (0);
}

int	end_pipe(t_mini *shell, int i)
{
	close(shell->pipes[(i - 1) % 2][1]);
	dup2(shell->pipes[(i - 1) % 2][0], STDIN_FILENO);
	if (!builts_in(shell))
		if (exec_bin(shell, shell->basic_env))
			return (1);
	return (0);
}