/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inoutfd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:57:52 by aliens            #+#    #+#             */
/*   Updated: 2022/01/05 15:49:00 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*init_inoutfd(char *command, t_cmd *cmd)
{
	char	*ret;
	int		fd;
	int		i;

	i = -1;
	ret = NULL;
	cmd->fdin = NULL;
	cmd->fdout = NULL;
	while (command[++i])
	{
		if (command[i] == '>' && command[i + 1] != '>')
		{
			if (!ret)
				ret = ft_substr(command, 0, i);
			cmd->fdout = get_file_name(command + i + 1);
			fd = open(cmd->fdout, O_CREAT);
			close(fd);
		}
		if (command[i] == '<' && command[i + 1] != '<')
		{
			if (!ret)
				ret = ft_substr(command, 0, i);
			cmd->fdin = get_file_name(command + i + 1);
			fd = open(cmd->fdin, O_RDONLY);
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
		if (command[i] == '<' && command[i + 1] == '<')
			cmd->heredoc = 1;
	}
	if (!ret)
		return (command);
	return (ret);
}
