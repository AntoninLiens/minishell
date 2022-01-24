/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:48:15 by aliens            #+#    #+#             */
/*   Updated: 2022/01/24 17:59:37 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int init(t_mini *shell, char **env)
{
	shell->cmd = NULL;
	shell->basic_env = env;
	shell->exit = 0;
	shell->fdin = 0;
	shell->fdout = 1;
	if (init_env(shell, env))
		return (1);
	up_shlvl(shell);
    return (0);
}