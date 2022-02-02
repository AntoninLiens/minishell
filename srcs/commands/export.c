/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:04:02 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/02 16:21:48 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**sort_env(char **export)
{
	char	*tmp;
	int		i;
	int		j;

	j = -1;
	while (export[++j])
		;
	while (--j)
	{
		i = -1;
		while (export[++i + 1])
		{
			if (ft_strncmp(export[i], export[i + 1], ft_strlen(export[i])) > 0)
			{
				tmp = export[i];
				export[i] = export[i + 1];
				export[i + 1] = tmp;
			}
		}
	}
	return (export);
}

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

int	verify_export(char *cmd)
{
	int	i;

	i = 0;
	while (ft_isalnum(cmd[i]))
		i++;
	if (!cmd[i] || cmd[i] == '=')
		return (0);
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
	return (1);
}

int	export(t_env *env, char **cmd)
{
	t_env	*tmp;

	if (!cmd[1])
		return (export_no_arg(env));
	tmp = env;
	if (verify_export(cmd[1]))
		return (1);
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
