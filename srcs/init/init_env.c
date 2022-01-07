/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:44:07 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/08 00:26:48 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int init_env(t_mini *shell, char **basic_env)
{
	t_env	*tmp;
	int		i;

	shell->env = (t_env *)malloc(sizeof(t_env));
	if (!shell->env)
		return (1);
	tmp = shell->env;
	i = -1;
	while (basic_env[++i])
	{
		tmp->str = ft_strdup(basic_env[i]);
		if (basic_env[i + 1])
		{
			tmp->next = (t_env *)malloc(sizeof(t_env));
			if (!tmp->next)
			{
				free_env(shell->env);
				return (1);
			}
			tmp = tmp->next;
		}
		else
			tmp->next = NULL;
	}
	return (0);
}