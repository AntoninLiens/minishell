/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:05:34 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/21 16:37:34 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void replace_oldpwd(t_env *env)
{
    t_env   *tmp;
    char    *old_pwd;

    tmp = env;
    old_pwd = get_env_val(env, "PWD");
    while (tmp)
    {
        if (!ft_strncmp("OLDPWD", tmp->str, 6))
        {
            free(tmp->str);
            tmp->str = ft_strjoin("OLDPWD=", old_pwd);
            return ;
        }
        tmp = tmp->next;
    }
}

static void replace_pwd(t_env *env)
{
    t_env   *tmp;
    char    new_pwd[200];

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

void    cd(t_mini *shell)
{
	char	**path;

	path = ft_split(shell->cmd->str, ' ');
    replace_oldpwd(shell->env);
    chdir(path[1]);
    replace_pwd(shell->env);
}
