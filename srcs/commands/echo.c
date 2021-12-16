/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:19:42 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/16 00:06:16 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    echo(char **cmds)
{
    int     i;

    i = 0;
    while (cmds[++i])
        ;
    if (cmds[1][0] == '\"')
    {
        cmds[i - 1][ft_strlen(cmds[i - 1]) - 1] = '\0';
        cmds[1]++;
        i = 0;
        while (cmds[++i])
            printf("%s ", cmds[i]);
        printf("\n");
    }
    else
        printf("%s\n", cmds[1]);
}
