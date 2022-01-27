/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/27 15:03:04 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	stop_parse_error(t_mini *shell)
{
	t_cmd	*tmp;

	tmp = shell->cmd;
	lst_first(&tmp);
	while (tmp)
	{
		if (tmp->end_parse_error)
		{
			shell->nb_cmds = 0;
			free_cmd(tmp);
			shell->cmd = NULL;
		}
		tmp = tmp->next;
	}
}

void	parser(char *ans, t_mini *shell)
{
	shell->nb_cmds = check_operator(ans, shell);
	stop_parse_error(shell);
	if (!shell->nb_cmds)
		return ;
	replace_env_variable(shell);
}
