/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:15:58 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/30 15:25:24 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_operator(char *ans, t_mini *shell)
{
	char	**cmd;
	char	**arg;
	int		nb_cmd;
	int		i;

	if (!ans[0])
		return (0);
	nb_cmd = 1;
	i = -1;
	while (ans[++i])
		if (ans[i] == '|')
			nb_cmd++;
	cmd = ft_split(ans, '|');
	i = -1;
	while(cmd[++i])
	{
		arg = ft_split(cmd[i],  ' ');
		add_command(shell, arg);
		free(arg);
	}
	free(arg);
	free(cmd);
	lst_first(&shell->cmd);
	return (nb_cmd);
}

int	parser(char *ans, t_mini *shell)
{
	pid_t	pid;
	t_cmd	*tmp;
	int		nb_cmds;
	int		i;

	nb_cmds = check_operator(ans, shell);
	while (shell->cmd && shell->cmd->next)
	{
		i = -1;
		while (shell->cmd->str[++i])
			printf("%d : %s\n", i, shell->cmd->str[i]);
		printf("------------------------\n");
	}
	//replace_env_variable(shell);
	if (!nb_cmds)
		return (0);
	tmp = shell->cmd;
	if (nb_cmds > 1)
	{
		redir(tmp->str, shell, 0);
		tmp = tmp->next;
		while (tmp && tmp->next)
		{
			redir(tmp->str, shell, 0);
			tmp = tmp->next;
		}
	}
	if (!tmp)
		return (0);
	if (!builts_in(shell, tmp->str))
	{
		pid = fork();
		if (!pid && exec_bin(shell->basic_env, tmp->str))	
			return (0);
		else
			waitpid(pid, 0, 0);
	}
	return (0);
}
