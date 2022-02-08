/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:08:15 by aliens            #+#    #+#             */
/*   Updated: 2022/02/08 18:18:25 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	replace_shlvl(t_env *env, char *sh_lvl)
{
	t_env	*tmp;
	int		i;

	tmp = env;
	while (tmp)
	{
		i = -1;
		while (tmp->str[++i] != '=')
			;
		if (!ft_strncmp(tmp->str, "SHLVL", i))
		{
			free(tmp->str);
			tmp->str = ft_strjoin("SHLVL=", sh_lvl);
		}
		tmp = tmp->next;
	}
	free(sh_lvl);
}

void	up_shlvl(t_mini *shell)
{
	char	**str;
	char	*shlvl;
	int		sh_lvl;

	str = NULL;
	shlvl = get_env_val(shell->env, "SHLVL");
	if (!shlvl)
	{
		export_name("SHLVL=1", shell->env, shell);
		free_double_char(str);
	}
	else
	{
		sh_lvl = ft_atoi(shlvl) + 1;
		free(shlvl);
		replace_shlvl(shell->env, ft_itoa(sh_lvl));
	}
}
