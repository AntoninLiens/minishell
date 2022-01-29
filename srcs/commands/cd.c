/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:05:34 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/29 01:43:36 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	replace_oldpwd(t_env *env)
{
	t_env	*tmp;
	char	*old_pwd;

	tmp = env;
	old_pwd = get_env_val(env, "PWD");
	while (tmp)
	{
		if (!ft_strncmp("OLDPWD", tmp->str, 6))
		{
			free(tmp->str);
			tmp->str = ft_strjoin("OLDPWD=", old_pwd);
			free(old_pwd);
			return ;
		}
		tmp = tmp->next;
	}
	free(old_pwd);
}

static void	replace_pwd(t_env *env)
{
	t_env	*tmp;
	char	new_pwd[200];

	getcwd(new_pwd, 200);
	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp("PWD", tmp->str, 3))
		{
			free(tmp->str);
			tmp->str = ft_strjoin("PWD=", new_pwd);
		}
		tmp = tmp->next;
	}
}

int	cd(t_mini *shell, char **cmd)
{
	char	*env_val;

	env_val = get_env_val(shell->env, "HOME");
	if (!cmd[1])
		chdir(env_val);
	else if (chdir(cmd[1]) < 0)
	{
		printf("cd: no such file or directory: %s\n", cmd[1]);
		return (1);
	}
	free(env_val);
	replace_oldpwd(shell->env);
	replace_pwd(shell->env);
	return (0);
}
