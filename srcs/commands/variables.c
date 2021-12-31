/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:04:02 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/31 17:45:54 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**sort_env(char **export)
{
	char	*tmp;
	int		i;
	int		j;
	
	j = -1;
	while(export[++j])
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

int	export_no_arg(t_env *env)
{
	char	**export;
	t_env	*tmp;
	int		i;

	tmp = env;
	export = (char **)malloc(sizeof(char *) * (ft_lstsize((t_list *)tmp) + 1));
	if (!export)
		return (-1);
	i = -1;
	while (tmp)
	{
		i++;
		export[i] = (char *)malloc(sizeof(char) * (ft_strlen(tmp->str) + 1));
		if (!export[i])
			return (-1);
		export[i] = tmp->str;
		tmp = tmp->next;
	}
	export = sort_env(export);
	i = -1;
	while (export[++i])
		printf("export %s\n", export[i]);
	return (0);
}

int	export(t_env *env, char **cmd)
{
    t_env   *tmp;

	if (!cmd[1])
		return (export_no_arg(env));
    tmp = env;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = (t_env *)malloc(sizeof(t_env));
    tmp->next->str = cmd[1];
    tmp->next->next = NULL;
	return (0);
}

void	unset(t_env *env, char *name)
{
    char    *res;
    t_env   *tmp;
    t_env   *tmp2;

    tmp = env;
    res = get_env_val(env, name);
    if (!res)
        return ;
    while (tmp->next)
    {
        if (!ft_strncmp(tmp->next->str, name, ft_strlen(name)))
        {
            tmp2 = tmp->next->next;
            free(tmp->next);
            tmp->next = tmp2;
            return ;
        }
        tmp = tmp->next;
    }
}
