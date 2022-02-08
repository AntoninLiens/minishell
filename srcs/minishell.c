/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:39:14 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/08 18:45:10 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(t_mini *shell)
{
	while (!shell->exit)
	{
		signals_default();
		shell->basic_env = NULL;
		shell->basic_env = transform_env(shell->env);
		if (!shell->basic_env)
			break ;
		shell->answer = readline("MINISHELL $ ");
		if (!shell->answer)
		{
			free_double_char(shell->basic_env);
			free_env(shell->env);
			printf("\n");
			return ;
		}
		add_history(shell->answer);
		parser(shell->answer, shell);
		if (big_exec(shell))
			shell->exit = 1;
		free_cmd(shell->cmd);
		free_double_char(shell->basic_env);
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
