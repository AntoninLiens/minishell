/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:22:45 by aliens            #+#    #+#             */
/*   Updated: 2022/01/04 18:17:34 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int big_exec(t_mini *shell, int nb_cmds)
{
	t_cmd	*tmp;

    tmp = shell->cmd;
	if (nb_cmds > 1)
	{
		redir(tmp->str, shell, 0);
		tmp = tmp->next;
		while (tmp && tmp->next)
		{
			redir(tmp->str, shell, 0);
			tmp = tmp->next;
		}
	}
	if (tmp && !builts_in(shell, tmp->str))
	{
		if (exec_bin(shell->basic_env, tmp->str, shell))
			return (1);
	}
	return (0);
}
