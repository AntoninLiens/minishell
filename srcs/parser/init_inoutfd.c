/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inoutfd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:57:52 by aliens            #+#    #+#             */
/*   Updated: 2022/02/03 16:54:00 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	fd_error(int fd, char *fd_error, t_cmd *cmd)
{
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		perror(fd_error);
		cmd->end_parse_error = 1;
		return (1);
	}
	return (0);
}

char	*init_infile(char *command, t_cmd *cmd, int *i, char *ret)
{
	int			error;
	int			fd;

	errno = 0;
	if (command[*i] == -4 && command[*i + 1] == -4)
	{
		if (!init_heredoc(cmd, command, i))
			return (NULL);
	}
	else if (command[*i] == -4 && command[*i + 1] != -4)
	{
		cmd->fdin = get_file_name(command + *i + 1);
		fd = open(cmd->fdin, O_RDONLY);
		error = errno;
		if (fd_error(fd, cmd->fdin, cmd))
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
	if (fd_error(fd, cmd->fdout, cmd))
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
	if (command[*i] == -5 && command[*i + 1] != -5)
	{
		cmd->fdout = get_file_name(command + *i + 1);
		fd = open(cmd->fdout, O_CREAT | O_TRUNC | O_WRONLY, 0664);
		error = errno;
		if (fd_error(fd, cmd->fdout, cmd))
			return (NULL);
		close(fd);
	}
	else if (command[*i] == -5 && command[*i + 1] == -5)
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
		if (command[i] == -4 || command[i] == -5)
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
