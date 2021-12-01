/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:39:14 by ctirions          #+#    #+#             */
/*   Updated: 2021/11/30 14:39:14 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	parse_answer(char *answer, char **env)
{
	(void)env;
	char	**cmd;
	int		i;

	i = -1;
	cmd = ft_split(answer, ' ');
	while (cmd[++i])
	{
		if (cmd[i] == "echo" || cmd[i] == "cd" || cmd[i] == "ls" || \
		cmd[i] == "pwd" || cmd[i] == "export" || cmd[i] == "unset" || \
		cmd[i] == "env")
			cass_exec(cmd[i], env);
		else if (cmd[i] == "exit")
			return (0);
		else
			return (1);
	}
}

int main(int ac, char **av, char **env)
{
	char *answer;
	(void)env;
	(void)av;

	if (ac > 1)
		return (1);
	while (1)
	{
		answer = readline("😁 \033[34mMINISHELL \033[31m$ \033[0m");
		if (!answer)
		{
			printf("\n");
			return (0);
		}
		add_history(answer);
		if (parse_answer(answer, env))
			return (1);
	}
	return (0);
}
