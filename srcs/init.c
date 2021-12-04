/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:43:50 by aliens            #+#    #+#             */
/*   Updated: 2021/12/04 16:05:01 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	init_env(t_mini *shell, char **basic_env)
{
	t_env	*tmp;
	int		i;

	shell->env = (t_env *)malloc(sizeof(t_env));
	if (!shell->env)
		return (1);
	i = -1;
	while (basic_env[++i])
	{
		tmp->str = ft_strdup(basic_env[i]);
		if (basic_env[i + 1])
		{
			tmp->next = (t_env *)malloc(sizeof(t_env));
			if (!tmp->next)
				return (1);
			tmp = tmp->next;
		}
		else
			tmp->next = NULL;
	}
}