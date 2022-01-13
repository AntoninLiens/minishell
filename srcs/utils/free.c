/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:09:12 by aliens            #+#    #+#             */
/*   Updated: 2022/01/13 17:56:10 by aliens           ###   ########.fr       */
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
	if (!cmd)
		return ;
    lst_first(&cmd);
    while(cmd->next)
    {
        cmd = cmd->next;
        free(cmd->prev);
    }
    free(cmd);
}