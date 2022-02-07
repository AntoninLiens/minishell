/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:16:08 by zminhas           #+#    #+#             */
/*   Updated: 2022/02/07 14:54:14 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	unset(char **arg, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (arg[++i])
	{
		j = -1;
		if (ft_isalpha(arg[i][0]))
		{
			while (ft_isalnum(arg[i][++j]))
				;
		}
		if (!ft_isalpha(arg[i][0]) || arg[i][j])
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(arg[i], STDERR_FILENO);
			ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
			return (1);
		}
		else
			unset_name(arg[i], env);
	}
	return (0);
}

void	unset_name(char *name, t_env *og_env)
{
	t_env	*env;
	t_env	*tmp;

	env = og_env;
	if (!ft_strncmp(name, env->str, ft_strlen(name)))
	{
		tmp = env->next;
		free(env);
		env = tmp;
		og_env = tmp;
	}
	while (env && env->next)
	{
		if (!ft_strncmp(name, env->next->str, ft_strlen(name)))
		{
			tmp = env->next->next;
			free(env->next);
			env->next = tmp;
		}
		env = env->next;
	}
}
