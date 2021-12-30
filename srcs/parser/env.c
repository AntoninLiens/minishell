/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:10:39 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/30 17:12:22 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*void	replace_env_variable(t_mini *shell)
{
	char	*res;
	char	*name;
	char	*value;
	int		i;
	int		j;

	i = -1;
	res = NULL;
	while (ans[++i])
	{
		j = 1;
		if (ans[i] == '$')
		{
			while (ans[i + j] && ans[i + j] != ' ')
				j++;
			name = ft_substr(ans, i + 1, j);
			value = get_env_val(shell->env, name);
			if (!value)
			{
				free(name);
				printf("\n");
				return (NULL);
			}
			res = ft_strjoin_mini(res, ft_substr(ans, 0, i - 1));
			res = ft_strjoin_mini(res, value);
			while (--i + j)
				ans++;
			i = 0;
			free(name);
		}
	}
	return (res);
}*/

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
