/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inoutfd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:57:52 by aliens            #+#    #+#             */
/*   Updated: 2022/02/01 13:49:33 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	fd_error(int fd, int error, char *fd_error, t_cmd *cmd)
{
	if (fd == -1)
	{
		printf("minishell: %s: %s\n", fd_error, strerror(error));
		cmd->end_parse_error = 1;
		return (1);
	}
	return (0);
}

char	*init_infile(char *command, t_cmd *cmd, int *i, char *ret)
{
	int	error;
	int	fd;

	errno = 0;
	if (command[*i] == '<' && command[*i + 1] == '<')
	{
		cmd->heredoc = 1;
		cmd->fdin = get_file_name(command + *i + 2);
		(*i)++;
	}
	else if (command[*i] == '<' && command[*i + 1] != '<')
	{
		cmd->fdin = get_file_name(command + *i + 1);
		fd = open(cmd->fdin, O_RDONLY);
		error = errno;
		if (fd_error(fd, error, cmd->fdin, cmd))
			return (NULL);
		close(fd);
	}
	return (ret);
}

char	*init_append_outfile(char *command, t_cmd *cmd, int *i, char *ret)
{
	int	fd;
	int	error;

	errno = 0;
	cmd->fdout = get_file_name(command + *i + 2);
	fd = open(cmd->fdout, O_CREAT | O_WRONLY, 0664);
	error = errno;
	if (fd_error(fd, error, cmd->fdout, cmd))
	{
		(*i)++;
		return (NULL);
	}
	cmd->append = 1;
	close(fd);
	(*i)++;
	return (ret);
}

char	*init_outfile(char *command, t_cmd *cmd, int *i, char *ret)
{
	int	error;
	int	fd;

	errno = 0;
	if (command[*i] == '>' && command[*i + 1] != '>')
	{
		cmd->fdout = get_file_name(command + *i + 1);
		fd = open(cmd->fdout, O_CREAT | O_TRUNC | O_WRONLY, 0664);
		error = errno;
		if (fd_error(fd, error, cmd->fdout, cmd))
			return (NULL);
		close(fd);
	}
	else if (command[*i] == '>' && command[*i + 1] == '>')
		return (init_append_outfile(command, cmd, i, ret));
	return (ret);
}

char	*init_inoutfd(char *command, t_cmd *cmd)
{
	char	*ret;
	int		i;

	i = -1;
	ret = NULL;
	while (command[++i])
	{
		if (command[i] == '<' || command[i] == '>')
		{
			if (!ret)
				ret = ft_substr(command, 0, i);
			ret = init_infile(command, cmd, &i, ret);
			ret = init_outfile(command, cmd, &i, ret);
		}
	}
	if (!ret)
		return (command);
	free(command);
	return (ret);
}
