/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:39:30 by aliens            #+#    #+#             */
/*   Updated: 2022/02/03 15:25:00 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	heredoc_no_cmd(t_cmd *cmd, char *line)
{
	int	i;

	i = 0;
	while (i < cmd->heredoc)
	{
		if (line)
			free(line);
		line = readline("> ");
		if (!ft_strncmp(cmd->limit_string[i], line, ft_strlen(cmd->limit_string[i])))
			i++;
	}
	free(line);
	return (0);
}

int	child_heredoc(t_cmd *cmd, char *line, int pipefd[2])
{
	int	i;

	i = 0;
	while (i < cmd->heredoc)
	{
		if (line && i == cmd->heredoc)
		{
			write(pipefd[1], line, ft_strlen(line));
			write(pipefd[1], "\n", 1);
			free(line);
		}
		line = readline("> ");
		if (!line)
			break ;
		if (!ft_strncmp(cmd->limit_string[i], line, ft_strlen(cmd->limit_string[i])))
			i++;
	}
	free(line);
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}

int	mini_heredoc(t_cmd *cmd)
{
	pid_t	pid;
	char	*line;
	int		pipefd[2];

	line = NULL;
	if (!cmd->str[0])
		return (heredoc_no_cmd(cmd, line));
	else
	{
		pipe(pipefd);
		pid = fork();
		if (!pid)
			exit(child_heredoc(cmd, line, pipefd));
		waitpid(pid, 0, 0);
		close(pipefd[1]);
	}
	dup2(pipefd[0], STDIN_FILENO);
	ctrl_c_default();
	return (pipefd[1]);
}

int	mini_inout(t_mini *shell, t_cmd *cmd)
{
	if (cmd->fdin)
	{
		if (shell->fdin)
			close(shell->fdin);
		if (!cmd->heredoc)
		{
			shell->fdin = open(cmd->fdin, O_RDONLY);
			dup2(shell->fdin, STDIN_FILENO);
		}
	}
	if (cmd->fdout)
	{
		if (shell->fdout)
			close(shell->fdout);
		if (cmd->append)
			shell->fdout = open(cmd->fdout, O_WRONLY | O_APPEND);
		else
			shell->fdout = open(cmd->fdout, O_WRONLY);
		dup2(shell->fdout, STDOUT_FILENO);
	}
	return (0);
}
