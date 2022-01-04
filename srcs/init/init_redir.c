/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:57:52 by aliens            #+#    #+#             */
/*   Updated: 2022/01/04 16:58:16 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int init_redir(t_mini *shell)
{
    t_cmd  *tmp;
    int     i;
    int     j;

    tmp = shell->cmd;
    while (tmp)
    {
        i = -1;
        while (tmp->str[++i])
        {
            j = -1;
            while (tmp->str[i][++j])
            {
                if (tmp->str[i][j] == '>')
                {
                    //get_dir_name(tmp->str);
                    shell->fdout = open("outfile", O_CREAT);
                    if (!shell->fdout)
                        return (1);
                }
            }
        }
    }
    return (0);
}
