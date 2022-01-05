/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inoutfd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:57:52 by aliens            #+#    #+#             */
/*   Updated: 2022/01/05 16:41:53 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *init_infile(char *command, t_cmd *cmd, int i, char *ret)
{
    int		fd;
        
	if (command[i] == '<' && command[i + 1] != '<')
	{
		if (!ret)
			ret = ft_substr(command, 0, i);
		cmd->fdin = get_file_name(command + i + 1);
		fd = open(cmd->fdin, O_RDONLY);
		close(fd);
	}
	if (command[i] == '<' && command[i + 1] == '<')
		cmd->heredoc = 1;
    return (ret);
}

char    *init_outfile(char *command, t_cmd *cmd, int i, char *ret)
{
	int		fd;

	if (command[i] == '>' && command[i + 1] != '>')
	{
		if (!ret)
			ret = ft_substr(command, 0, i);
		cmd->fdout = get_file_name(command + i + 1);
		fd = open(cmd->fdout, O_CREAT);
		close(fd);
	}
	if (command[i] == '>' && command[i + 1] == '>')
	{
		if (!ret)
			ret = ft_substr(command, 0, i);
		cmd->fdout = get_file_name(command + i + 2);
		fd = open(cmd->fdout, O_CREAT);
		close(fd);
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
        ret = init_infile(command, cmd, i, ret);
        ret = init_outfile(command, cmd, i, ret);
	}
	if (!ret)
		return (command);
	return (ret);
}
