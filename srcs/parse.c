/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/16 00:09:12 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    parser(char *ans, t_mini *shell)
{
    char **cmds;

    if (!ans[0])
        return ;
    cmds = ft_split(ans, ' ');
    if (!ft_strncmp(cmds[0], "pwd", 4))
        pwd(shell->env);
    else if (!ft_strncmp(cmds[0], "env", 4))
        env(shell->env);
    else if (!ft_strncmp(cmds[0], "exit", 5))
        shell->exit = 1;
    else if (!ft_strncmp(cmds[0], "export", 7))
        export(shell->env, cmds[1]);
    else if (!ft_strncmp(cmds[0], "unset", 6))
        unset(shell->env, cmds[1]);
    else if (!ft_strncmp(cmds[0], "echo", 5))
        echo(cmds);
    else if (!ft_strncmp(cmds[0], "cd", 3))
        cd(cmds[1], shell);
    else
        printf("minishell: command not found: %s\n", cmds[0]); 
}