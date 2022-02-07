/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:39:14 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/07 13:53:59 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(t_mini *shell)
{
	signals_default();
	while (!shell->exit)
	{
		shell->answer = readline("MINISHELL $ ");
		if (!shell->answer)
		{
			free_env(shell->env);
			printf("\n");
			return ;
		}
		add_history(shell->answer);
		parser(shell->answer, shell);
		if (big_exec(shell))
			shell->exit = 1;
		free_cmd(shell->cmd);
		signals_default();
	}
	free_env(shell->env);
}

int	main(int argc, char **argv, char **env)
{
	t_mini	shell;

	if (argc > 1 && argv)
		return (1);
	if (init(&shell, env))
		return (1);
	minishell(&shell);
	return (shell.exit_status);
}
