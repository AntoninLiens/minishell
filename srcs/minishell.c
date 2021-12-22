/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@students.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:39:14 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/22 15:59:28 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv, char **env)
{
	t_mini	shell;

	shell.basic_env = env;
	if (argc > 1 && argv)
		return (1);
	shell.exit = 0;
	if (init_env(&shell, env))
		return (1);
	up_shlvl(&shell);
	while (!shell.exit)
	{
		signal(SIGINT, &sigint);
		shell.answer = readline("MINISHELL $ ");
		if (!shell.answer)
		{
			printf("\n");
			return (1);
		}
		add_history(shell.answer);
		if (parser(shell.answer, &shell))
			shell.exit = 1;
	}
	free_env(shell.env);
	return (0);
}
