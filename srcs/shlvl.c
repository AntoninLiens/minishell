/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2021/12/04 16:08:19 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/04 16:55:02 by ctirions         ###   ########.fr       */
=======
/*   Created: 2021/12/04 16:08:15 by aliens            #+#    #+#             */
/*   Updated: 2021/12/04 16:09:14 by aliens           ###   ########.fr       */
>>>>>>> e2b4fdc2efa7828e7b506503a0fe3f27569182b0
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

<<<<<<< HEAD
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
=======
void	up_shlvl(t_mini *shell)
{
	
>>>>>>> e2b4fdc2efa7828e7b506503a0fe3f27569182b0
}