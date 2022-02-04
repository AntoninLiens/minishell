/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:04:02 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/04 16:04:33 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	norm_2(char **export, t_env *tmp)
{
	int	i;

	i = -1;
	while (tmp)
	{
		i++;
		export[i] = ft_strdup(tmp->str);
		if (!export[i])
		{
			free_double_char(export);
			return (-1);
		}
		tmp = tmp->next;
	}
	return (i);
}

int	export_no_arg(t_env *env)
{
	char	**export;
	t_env	*tmp;
	int		i;

	if (!env)
		return (0);
	tmp = env;
	export = (char **)malloc(sizeof(char *) * (ft_lstsize((t_list *)tmp) + 1));
	if (!export)
		return (-1);
	i = norm_2(export, tmp);
	export[i + 1] = NULL;
	export = sort_env(export);
	i = -1;
	while (export[++i])
		printf("declare -x %s\n", export[i]);
	free_double_char(export);
	return (0);
}

int	already_exist(char *cmd, int i, t_env *env)
{
	char	*name;
	t_env	*tmp;

	tmp = env;
	name = ft_substr(cmd, 0, i);
	while (env)
	{
		if (!ft_strncmp(env->str, cmd, i))
			unset_name(name, tmp);
		env = env->next;
	}
	free(name);
	return (0);
}

int	verify_export(char *cmd, t_env *env)
{
	int		i;

	i = 0;
	if (ft_isalpha(cmd[0]))
	{
		while (ft_isalnum(cmd[i]))
			i++;
		if (!cmd[i])
			return (0);
		else if (cmd[i] == '=')
			return (already_exist(cmd, i, env));
	}
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
	return (1);
}

int	export(t_env *env, char **cmd)
{
	t_env	*tmp;
	int		i;

	tmp = env;
	if (!cmd[1])
		return (export_no_arg(tmp));
	i = 0;
	while (cmd[++i])
	{
		if (verify_export(cmd[i], tmp))
			return (1);
	}
	if (!ft_strrchr(cmd[1], '='))
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_env *)malloc(sizeof(t_env));
	if (!tmp->next)
		return (-1);
	tmp->next->str = ft_strdup(cmd[1]);
	tmp->next->next = NULL;
	return (0);
}
