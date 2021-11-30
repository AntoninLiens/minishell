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

int main(void)
{
	char *answer;
	int  i;

	i = -1;
	while (++i < 10)
	{
		answer = readline("😁 \033[34mMINISHELL \033[31m$ \033[0m");
		if (!answer)
		{
			printf("\n");
			return (0);
		}
		add_history(answer);
		printf("%s\n", answer);
	}
	return (0);
}
