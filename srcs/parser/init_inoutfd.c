/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inoutfd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:57:52 by aliens            #+#    #+#             */
/*   Updated: 2022/01/05 14:21:36 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int init_inoutfd(t_mini *shell)
{
    t_cmd   *tmp;
    char    *name;
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
                    if (tmp->str[i][j + 1])
                        name = get_file_name(tmp->str[i] + j + 1);
                    else
                        name = get_file_name(tmp->str[i + 1]);
                    if (!name)
                        return (-1);
                    shell->fdout = open(name, O_CREAT);
                    if (!shell->fdout)
                        return (1);
                }
                else if (tmp->str[i][j] == '<')
                {
                    if (tmp->str[i][j + 1])
                        name = get_file_name(tmp->str[i] + j + 1);
                    else
                        name = get_file_name(tmp->str[i + 1]);
                    if (!name)
                        return (-1);
                    shell->fdin = open(name, O_RDONLY);
                    if (!shell->fdin)
                        return (1);
                }
            }
        }
        tmp = tmp->next;
    }
    return (0);
}
