/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:09:18 by aliens            #+#    #+#             */
/*   Updated: 2022/01/21 13:02:29 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_close_quotes(char **cmd)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (cmd[++i])
	{
		j = -1;
		while (cmd[i][++j])
		{
			if (cmd[i][j] == '\'' || cmd[i][j] == '\"')
			{
				k = 1;
				while (cmd[i][j + k] && cmd[i][j + k] != cmd[i][j])
					k++;
				if (!cmd[i][j + k])
					return (1);
				j += k;
			}
		}
	}
	return (0);
}

char	*quotes(char *command, t_cmd *cmd)
{
	char	*ret;
	int		i;
	int		j;

	i = -1;
	while (command[++i])
	{
		if (command[i] == '\'')
		{
			j = 1;
			cmd->s_quotes++;
			ret = ft_substr(command, 0, i);
			while(command[i + j] && command[i + j] != command[i])
				j++;
			ret = ft_strjoin(ret, ft_substr(command, i + 1, j - 1));
			i += j;
			j = 0;
			while (command[i + j])
				j++;
			ret = ft_strjoin(ret, ft_substr(command, i, j));
		}
		if (command[i] == '\"')
		{
			j = 1;
			cmd->d_quotes++;
			ret = ft_substr(command, 0, i);
			while(command[i + j] && command[i + j] != command[i])
				j++;
			ret = ft_strjoin(ret, ft_substr(command, i + 1, j - 1));
			i += j;
			j = 0;
			while (command[i + j])
				j++;
			ret = ft_strjoin(ret, ft_substr(command, i + 1, j));
		}
		
	}
	return (ret);
}

int	check_quotes(char **cmd)
{
	if (check_close_quotes(cmd))
		return (1);
	return (0);
}

int	add_command(t_mini *shell, char *command)
{
	if (!shell->cmd)
	{
		shell->cmd = (t_cmd *)malloc(sizeof(t_cmd));
		if (!shell->cmd)
			return (1);
		shell->cmd->end_parse_error = 0;
		shell->cmd->heredoc = 0;
		shell->cmd->append = 0;
		shell->cmd->s_quotes = 0;
		shell->cmd->d_quotes = 0;
		shell->cmd->prev = NULL;
		shell->cmd->next = NULL;
		command = quotes(command, shell->cmd);
		command = init_inoutfd(command, shell->cmd);
		if (shell->cmd->end_parse_error)
			return (1);
		shell->cmd->str = ft_split(command, ' ');
	}
	else
	{
		shell->cmd->next = (t_cmd *)malloc(sizeof(t_cmd));
		if (!shell->cmd->next)
			return (1);
		shell->cmd->next->end_parse_error = 0;
		shell->cmd->next->heredoc = 0;
		shell->cmd->next->append = 0;
		shell->cmd->s_quotes = 0;
		shell->cmd->d_quotes = 0;
		shell->cmd->next->prev = shell->cmd;
		shell->cmd->next->next = NULL;
		command = quotes(command, shell->cmd->next);
		command = init_inoutfd(command, shell->cmd->next);
		if (shell->cmd->next->end_parse_error)
			return (1);
		shell->cmd->next->str = ft_split(command, ' ');
		shell->cmd = shell->cmd->next;
	}
	return (0);
}

int	check_operator(char *ans, t_mini *shell)
{
	char	**cmd;
	int		nb_cmd;
	int		i;

	shell->cmd = NULL;
	if (!ans[0])
		return (0);
	nb_cmd = 1;
	i = -1;
	while (ans[++i])
		if (ans[i] == '|')
			nb_cmd++;
	cmd = ft_split(ans, '|');
	if (check_quotes(cmd))
	{
		printf("minishell: quotes not closed\n");
		return (0);
	}		
	i = -1;
	while(cmd[++i])
	{
		if (add_command(shell, cmd[i]))
		{
			free_cmd(shell->cmd);
			return (0);
		}
	}
	lst_first(&shell->cmd);
	return (nb_cmd);
}
