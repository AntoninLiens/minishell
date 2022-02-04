/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:04:02 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/04 17:40:38 by aliens           ###   ########.fr       */
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

void	already_exist(char *cmd, t_env *env)
{
	char	*name;
	t_env	*tmp;
	t_env	*tmp2;
	int		i;

	tmp = env;
	tmp2 = env;
	i = 0;
	while (cmd[i] && cmd[i] != '=')
		i++;
	name = ft_substr(cmd, 0, i);
	while (tmp2)
	{
		if (!ft_strncmp(tmp2->str, cmd, i))
			unset_name(name, tmp);
		tmp2 = tmp2->next;
	}
	free(name);
}

void	export_name(char *line, t_env *og_env)
{
	t_env	*tmp;

	tmp = og_env;
	already_exist(line, og_env);
	if (!ft_strrchr(line, '='))
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_env *)malloc(sizeof(t_env));
	if (!tmp->next)
		return ;
	tmp->next->str = ft_strdup(line);
	tmp->next->next = NULL;
}

int	export(t_env *env, char **cmd)
{
	int		i;
	int		j;
	t_env	*tmp;

	tmp = env;
	if (!cmd[1])
		return (export_no_arg(tmp));
	i = 0;
	while (cmd[++i])
	{
		j = 0;
		if (ft_isalpha(cmd[i][0]))
			while (ft_isalnum(cmd[i][j]))
				j++;
		if (!ft_isalpha(cmd[i][0]) || (cmd[i][j] && cmd[i][j] != '='))
		{
			ft_putstr_fd("minishell: export: `", STDERR_FILENO);
			ft_putstr_fd(cmd[i], STDERR_FILENO);
			ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
			return (1);
		}
		else
			export_name(cmd[i], env);
	}
	return (0);
}
