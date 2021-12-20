/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:20:04 by aliens            #+#    #+#             */
/*   Updated: 2021/12/20 16:42:44 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	**malloc_pipes(int size, t_mini *shell)
{
	int	**pipes;
	int	i;

	pipes = (int **)malloc(sizeof(int *) * (size + 1));
	if (!pipes)
		return (NULL);
	pipes[size] = NULL;
	while (size--)
	{
		pipes[size] = (int *)malloc(sizeof(int) * 2);
		if (!pipes[size])
			return (NULL);
	}
	i = -1;
	while (++i < size)
	{
		if (pipe(shell->pipes[i]) == -1)
			return (NULL);
	}
	return (pipes);
}

int	begin_pipe(char *ans, t_mini *shell, int i)
{
	close(shell->pipes[i][0]);
	dup2(shell->pipes[i][1], STDOUT_FILENO);
	if (i)
		dup2(shell->pipes[i - 1][0], STDIN_FILENO);
	if (!builts_in(ans, shell))
		if (make_my_actions(shell->answer, shell->basic_env))
			return (1);
	return (0);
}

int	end_pipe(char *ans, t_mini *shell, int i)
{
	close(shell->pipes[i][1]);
	dup2(shell->pipes[i][0], STDIN_FILENO);
	dup2(STDOUT_FILENO, shell->pipes[i - 1][1]);
	if (!builts_in(ans, shell))
		if (make_my_actions(shell->answer, shell->basic_env))
			return (1);
	return (0);
}