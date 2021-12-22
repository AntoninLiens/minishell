/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@students.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:20:04 by aliens            #+#    #+#             */
/*   Updated: 2021/12/22 18:00:53 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	common_pipes(t_mini *shell)
{
	close(shell->pipes[0]);
	dup2(shell->pipes[1], STDOUT_FILENO);
	if (!builts_in(shell))
	{
		if (exec_bin(shell, shell->basic_env))
			return (1);
	}
	else
		exit(1);
	return (0);
}

int	end_pipe(t_mini *shell)
{
	close(shell->pipes[1]);
	dup2(shell->pipes[0], STDIN_FILENO);
	if (!builts_in(shell))
	{
		if (exec_bin(shell, shell->basic_env))
			return (1);
	}
	else
		exit(1);
	return (0);
}

/*void    malloc_pipes(int size, t_mini *shell)
{
    int    i;

    shell->pipes = (int **)malloc(sizeof(int *) * (size));
    if (!shell->pipes)
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
}*/
