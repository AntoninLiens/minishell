/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:04:02 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/16 00:06:30 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    export(t_env *env, char *arg)
{
    t_env   *tmp;   

    tmp = env;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = (t_env *)malloc(sizeof(t_env));
    tmp->next->str = arg;
    tmp->next->next = NULL;
}

void    unset(t_env *env, char *name)
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
