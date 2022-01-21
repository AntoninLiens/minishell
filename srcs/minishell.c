/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:39:14 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/21 18:53:11 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(t_mini shell)
{
	ctrl_c_default();
	while (!shell.exit)
	{
		shell.answer = readline("MINISHELL $ ");
		if (!shell.answer)
		{
			printf("\n");
			return ;
		}
		add_history(shell.answer);
		if (parser(shell.answer, &shell))
			shell.exit = 1;
		if (big_exec(&shell))
			shell.exit = 1;
		printf("status : %d\n", shell.exit_status);
		free_cmd(shell.cmd);
		ctrl_c_default();
	}
}

int main(int argc, char **argv, char **env)
{
	t_mini	shell;
	
	if (argc > 1 && argv)
		return (1);
	if (init(&shell, env))
		return (1);
	minishell(shell);
	free_env(shell.env);
	return (shell.exit_status);
}
