/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/05 14:32:28 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parser(char *ans, t_mini *shell)
{
	int		nb_cmds;

	nb_cmds = check_operator(ans, shell);
	replace_env_variable(shell);
	if (!nb_cmds)
		return (0);
	if (big_exec(shell, nb_cmds))
		return (1);
	return (0);
}
