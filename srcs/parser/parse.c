/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/11 16:13:07 by aliens           ###   ########.fr       */
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

int	parser(char *ans, t_mini *shell)
{
	shell->nb_cmds = check_operator(ans, shell);
	stop_parse_error(shell);
	replace_env_variable(shell);
	if (!shell->nb_cmds)
		return (0);
	return (0);
}
