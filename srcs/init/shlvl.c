/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:08:15 by aliens            #+#    #+#             */
/*   Updated: 2022/01/08 00:26:57 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    replace_shlvl(t_env *env, char *sh_lvl)
{
    t_env   *tmp;
    int     i;

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
}

void    up_shlvl(t_mini *shell)
{
    char    *shlvl;
    int     sh_lvl;

    shlvl = get_env_val(shell->env, "SHLVL");
    sh_lvl = ft_atoi(shlvl) + 1;
    replace_shlvl(shell->env, ft_itoa(sh_lvl));
}