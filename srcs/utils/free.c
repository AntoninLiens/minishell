/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:09:12 by aliens            #+#    #+#             */
/*   Updated: 2022/01/27 17:35:17 by ctirions         ###   ########.fr       */
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
		env = env->next;
		free(tmp->str);
		free(tmp);
	}
	free(env->str);
	free(env);
}

void    free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	if (!cmd)
		return ;
    lst_first(&cmd);
    while(cmd)
    {
		tmp = cmd;
		if (cmd->fdin)
			free(cmd->fdin);
		if (cmd->fdout)
			free(cmd->fdout);
		free_double_char(cmd->str);
        cmd = cmd->next;
        free(tmp);
    }
	free(cmd);
}

void	free_double_char(char **str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str[i]);
	free(str);
}