/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/06 15:36:37 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	stop_parse_error(t_mini *shell, int *nb_cmds)
{
	t_cmd	*tmp;

	tmp = shell->cmd;
	lst_first(&tmp);
	while (tmp)
	{
		if (tmp->end_parse_error)
		{
			*nb_cmds = 0;
			free_cmd(tmp);
			shell->cmd = NULL;
		}
		tmp = tmp->next;
	}
}

int	parser(char *ans, t_mini *shell)
{
	int		nb_cmds;

	nb_cmds = check_operator(ans, shell);
	stop_parse_error(shell, &nb_cmds);
	replace_env_variable(shell);
	if (!nb_cmds)
		return (0);
	if (big_exec(shell, nb_cmds))
		return (1);
	return (0);
}
