/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/01 13:15:05 by aliens           ###   ########.fr       */
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
			return ;
		}
		tmp = tmp->next;
	}
}

void	parser(char *ans, t_mini *shell)
{
	shell->cmd = NULL;
	shell->nb_cmds = check_operator(ans, shell);
	stop_parse_error(shell);
	if (!shell->nb_cmds)
		return ;
	replace_spec_char(shell);
}
