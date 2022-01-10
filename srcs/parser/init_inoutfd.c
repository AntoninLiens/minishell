/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inoutfd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:57:52 by aliens            #+#    #+#             */
/*   Updated: 2022/01/10 16:39:26 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *init_infile(char *command, t_cmd *cmd, int *i, char *ret)
{
    int	fd;
	int	error;

	errno = 0;
	if (command[*i] == '<' && command[*i + 1] == '<')
	{
		cmd->heredoc = 1;
		if (!ret)
			ret = ft_substr(command, 0, *i);
		cmd->fdin = get_file_name(command + *i + 2);
		(*i)++;
	}
	else if (command[*i] == '<' && command[*i + 1] != '<')
	{
		if (!ret)
			ret = ft_substr(command, 0, *i);
		cmd->fdin = get_file_name(command + *i + 1);
		fd = open(cmd->fdin, O_RDONLY);
		error = errno;
		if (fd == -1)
		{
			printf("minishell: %s: %s\n", cmd->fdin, strerror(error));
			cmd->end_parse_error = 1;
		}
		close(fd);
	}
    return (ret);
}

char    *init_outfile(char *command, t_cmd *cmd, int *i, char *ret)
{
	int	fd;
	int	error;

	errno = 0;
	if (command[*i] == '>' && command[*i + 1] != '>')
	{
		if (!ret)
			ret = ft_substr(command, 0, *i);
		cmd->fdout = get_file_name(command + *i + 1);
		printf("%c\n", command[*i + 1]);
		fd = open(cmd->fdout, O_CREAT | O_TRUNC | O_WRONLY, 0664);
		error = errno;
		if (fd == -1)
		{
			printf("minishell: %s: %s\n", cmd->fdin, strerror(error));
			cmd->end_parse_error = 1;		
		}
		close(fd);
	}
	if (command[*i] == '>' && command[*i + 1] == '>')
	{
		if (!ret)
			ret = ft_substr(command, 0, *i);
		cmd->fdout = get_file_name(command + *i + 2);
		fd = open(cmd->fdout, O_CREAT | O_WRONLY, 0664);
		if (fd == -1)
		{
			printf("minishell: %s: %s\n", cmd->fdin, strerror(error));
			cmd->end_parse_error = 1;	
		}
		cmd->append = 1;
		close(fd);
		(*i)++;
	}
    return (ret);
}

char	*init_inoutfd(char *command, t_cmd *cmd)
{
	char	*ret;
	int		i;

	i = -1;
	ret = NULL;
	cmd->fdin = NULL;
	cmd->fdout = NULL;
	while (command[++i])
	{
        ret = init_infile(command, cmd, &i, ret);
        ret = init_outfile(command, cmd, &i, ret);
	}
	if (!ret)
		return (command);
	return (ret);
}
