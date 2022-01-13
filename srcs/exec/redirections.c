/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:39:30 by aliens            #+#    #+#             */
/*   Updated: 2022/01/13 17:12:10 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	heredoc_no_cmd(t_cmd *cmd, char *line)
{
	while (ft_strncmp(cmd->fdin, line, ft_strlen(cmd->fdin)))
	{
		if (line)
			free(line);
		line = readline("> ");	
	}
	free(line);
	return (0);
}

int	child_heredoc(t_cmd *cmd, char *line, int pipefd[2])
{
	while (ft_strncmp(cmd->fdin, line, ft_strlen(cmd->fdin)))
	{
		if (line)
		{
			write(pipefd[1], line, ft_strlen(line));
			write(pipefd[1], "\n", 1);
			free(line);
		}
		line = readline("> ");
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
	dup2(pipefd[0], 0);
	return (pipefd[1]);
}

void	mini_inout(t_mini *shell, t_cmd *cmd)
{
	if (cmd->fdin)
	{
		if (!cmd->heredoc)
		{
			shell->fdin = open(cmd->fdin, O_RDONLY);
			dup2(shell->fdin, 0);
		}
	}
	if (cmd->fdout)
	{
		if (cmd->append)
			shell->fdout = open(cmd->fdout, O_WRONLY | O_APPEND);
		else
			shell->fdout = open(cmd->fdout, O_WRONLY);
		dup2(shell->fdout, 1);
	}
}
