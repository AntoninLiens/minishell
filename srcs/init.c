/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:44:07 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/04 16:03:52 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int init_env(t_mini *shell, char **basic_env)
{
	t_env	*tmp;
	int		i;

	i = -1;
	
	shell->env = (t_env *)malloc(sizeof(t_env));
	tmp = shell->env;
	while (basic_env[++i])
	{
		tmp->str = ft_strdup(basic_env[i]);
		if (basic_env[i + 1])
		{
			tmp->next = (t_env *)malloc(sizeof(t_env));
			tmp = tmp->next;
		}
		else
			tmp->next = NULL;
	}
	return (0);
}