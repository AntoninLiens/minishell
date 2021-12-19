/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@students.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/16 16:44:30 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_quote(char **cmds)
{
	
}

static int	builts_in(char *ans, t_mini *shell)
{
	char	**cmds;

	if (!ans[0])
        return (1);
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
		return (0);
	return (1);
}

int	parser(char *ans, t_mini *shell)
{
	
	return (builts_in(ans, shell));
}