/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:09:12 by aliens            #+#    #+#             */
/*   Updated: 2022/01/24 18:03:27 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_env(t_env *env)
{
	t_env	*tmp;

	if (!env)
		return ;
	while (env->next)
	{
		tmp = env;
		env = tmp->next;
		free(tmp);
	}
	free(env);
}

void    free_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
    lst_first(&cmd);
    while(cmd->next)
    {
		if (cmd->fdin)
			free(cmd->fdin);
		if (cmd->fdout)
			free(cmd->fdout);
        cmd = cmd->next;
        free(cmd->prev);
    }
   	free(cmd);
	cmd = NULL;
}