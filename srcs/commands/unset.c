/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:16:08 by zminhas           #+#    #+#             */
/*   Updated: 2022/02/04 14:26:15 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	unset(t_env *og_env, char **arg)
{
	t_env	*env;
	t_env	*tmp;
	int		i;

	i = -1;
	while (arg[++i])
	{
		env = og_env;
		if (!ft_strncmp(arg[i], env->str, ft_strlen(arg[i])))
		{
			tmp = env->next;
			free(env);
			env = tmp;
			og_env = tmp;
		}
		while (env->next)
		{
			if (!ft_strncmp(arg[i], env->next->str, ft_strlen(arg[i])))
			{
				printf("coucou\n");
				tmp = env->next->next;
				free(env->next);
				env->next = tmp;
			}
			env = env->next;
		}
	}
	return (0);
}
