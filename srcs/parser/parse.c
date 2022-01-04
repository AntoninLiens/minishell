/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/04 19:05:04 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parser(char *ans, t_mini *shell)
{
	int		nb_cmds;

	nb_cmds = check_operator(ans, shell);
	lst_first(&shell->cmd);
	replace_env_variable(shell);
	//init_inoutfd(shell);
	if (!nb_cmds)
		return (0);
	if (big_exec(shell, nb_cmds))
		return (1);
	return (0);
}
