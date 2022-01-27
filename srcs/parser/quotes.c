/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:11:00 by aliens            #+#    #+#             */
/*   Updated: 2022/01/27 15:06:46 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*quotes(char *command)
{
	char	*tmp;
	char	*ret;
	int		i;
	int		j;

	if (close_quotes(command))
		return (NULL);
	ret = NULL;
	i = 0;
	while (command[i] && command[i] != '\"' && command[i] != '\'')
	{
		if (command[i] == '$')
			command[i] = -2;
		else if (command[i] == '|')
			command[i] = -3;
		i++;
	}
	if (!command[i])
		return (command);
	ret = ft_substr(command, 0, i);
	while (command[i])
	{
		if (command[i] == '\'' || command[i] == '\"')
		{
			j = 1;	
			while (command[i + j] != command[i])
			{
				if (command[i + j] == '$' && command[i] == '\"')
					command[i + j] = -2;
				else if (command[i + j] == ' ')
					command[i + j] = -1;
				j++;
			}
			tmp = ft_substr(command, i + 1, j - 1);
			ret = ft_strjoin_gnl(ret, tmp);
			free(tmp);
			i += j + 1;
		}
		j = 0;
		while (command[i + j] && \
		command[i + j] != '\"' && command[i + j] != '\'')
		{
			if (command[i + j] == '$')
				command[i + j] = -2;
			else if (command[i] == '|')
				command[i] = -3;
			j++;
		}
		if (j)
		{
			tmp = ft_substr(command, i, j);
			ret = ft_strjoin_gnl(ret, tmp);
			free(tmp);
		}
		i += j;
	}
	free(command);
	return (ret);
}

int	close_quotes(char *cmd)
{
	int	i;
	int	j;

	i = -1;
	while (cmd[++i])
	{
		j = 1;
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			while (cmd[i + j] && cmd[i + j] != cmd[i])
				j++;
			if (!cmd[i + j])
			{
				free(cmd);
				return (printf("minishell: quotes not closed\n"));
			}
			i += j;
		}
	}
	return (0);
}
