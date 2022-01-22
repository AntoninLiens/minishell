/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:11:00 by aliens            #+#    #+#             */
/*   Updated: 2022/01/22 21:12:58 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*quotes(char *command, t_cmd *cmd)
{
	char	*ret;
	int		i;
	int		j;
	(void)cmd;

	ret = NULL;
	i = -1;
	while (command[++i])
	{
		if (command[i] == '\"' || command[i] == '\'')
			break ;
	}
	if (!command[i])
		return (command);
	ret = ft_substr(command, 0, i);
	while (command[i])
	{
		if (command[i] == '\'')
		{
			cmd->s_quotes++;
			j = 1;
			while (command[i + j] != command[i])
				j++;
			ret = ft_strjoin(ret, ft_substr(command, i + 1, j - 1));
			i += j + 1;
			if (!command[i])
				return (ret);
		}
		if (command[i] == '\"')
		{
			cmd->d_quotes++;
			j = 1;
			while (command[i + j] != command[i])
				j++;
			ret = ft_strjoin(ret, ft_substr(command, i + 1, j - 1));
			i += j + 1;
			if (!command[i])
				return (ret);
		}
		j = 0;
		while (command[i + j])
		{
			if (command[i + j] == '\"' || command[i + j] == '\'')
				break ;
			j++;
		}
		ret = ft_strjoin(ret, ft_substr(command, i, j));
		i += j;
		i++;
	}
	return (ret);
}

int	close_quotes(char **cmd)
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
					return (0);
				j += k;
			}
		}
	}
	return (1);
}
