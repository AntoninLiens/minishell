/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@students.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:10:39 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/22 17:56:36 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char    *get_env_val(t_env *env, char *name)
{
	t_env	*tmp;
	char	*res;
	int		i;

	tmp = env;
	while (tmp)
	{
		i = -1;
		while (tmp->str[++i] != '=')
			;
		res = ft_substr(tmp->str, 0, i);
		if (!ft_strncmp(name, res, ft_strlen(res) + 1))
		{
			free(res);
			return (ft_substr(tmp->str, i + 1, ft_strlen(tmp->str) - i));
		}
		free(res);
		tmp = tmp->next;
	}
	return (NULL);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env->next)
	{
		tmp = env;
		env = tmp->next;
		free(tmp);
	}
	free(env);
}
