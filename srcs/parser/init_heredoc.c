/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:44:25 by zminhas           #+#    #+#             */
/*   Updated: 2022/02/03 16:52:23 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init_heredoc(t_cmd *cmd, char *command, int *i)
{
	static int	j;

	if (!cmd->heredoc)
	{
		j = *i - 1;
		while (command[++j])
		{
			if (command[j] == -4 && command[j + 1] == -4)
				cmd->heredoc++;
		}
		cmd->limit_string = (char **)malloc(sizeof(char *) * cmd->heredoc + 1);
		if (!cmd->limit_string)
			return (0);
		cmd->limit_string[cmd->heredoc] = 0;
		j = 0;
	}
	cmd->limit_string[j++] = get_file_name(command + *i + 2);
	(*i)++;
	return (1);
}
