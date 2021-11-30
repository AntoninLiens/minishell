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

int main(int argc, char **argv, char **env)
{
	char *answer;
	int  i;

	argc = 0;
	argv = NULL;
	i = -1;
	answer = readline("😁 \033[34mMINISHELL \033[31m$ \033[0m");
	while (answer)
	{
		add_history(answer);
		make_my_actions(answer, env, &data);
		answer = readline("😁 \033[34mMINISHELL \033[31m$ \033[0m");
	}
	printf("\n");
	return (0);
}

void	make_my_actions(char *ans, char **env, t_data *data)
{
	char **cmd;

	cmd = ft_split(ans, ' ');
	if (cmd[0] == "echo")
		;
	else if (ans == )
}
