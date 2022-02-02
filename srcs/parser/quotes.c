/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:11:00 by aliens            #+#    #+#             */
/*   Updated: 2022/02/02 18:35:14 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
				ft_putstr_fd("minishell: quotes not closed\n", 2);
				return (1);
			}
			i += j;
		}
	}
	return (0);
}

int	before_quotes(char *command)
{
	int	i;

	i = 0;
	while (command[i] && command[i] != '\"' && command[i] != '\'')
	{
		if (command[i] == '$')
			command[i] = -2;
		else if (command[i] == '|')
			command[i] = -3;
		else if (command[i] == '<')
			command[i] = -4;
		else if (command[i] == '>')
			command[i] = -5;
		i++;
	}
	return (i);
}

int	in_quotes(char *command, char **ret)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = NULL;
	if (*command == '\'' || *command == '\"')
	{
		while (command[i] != *command)
		{
			if (command[i] == '$' && *command == '\"')
				command[i] = -2;
			else if (command[i] == ' ')
				command[i] = -1;
			i++;
		}
		tmp = ft_substr(command, 1, i - 1);
		*ret = ft_strjoin_gnl(*ret, tmp);
		free(tmp);
	}
	return (i + 1);
}

int	after_quotes(char *command, char **ret)
{
	char	*tmp;
	int		i;

	i = 0;
	while (command[i] && \
	command[i] != '\"' && command[i] != '\'')
	{
		if (command[i] == '$')
			command[i] = -2;
		else if (command[i] == '|')
			command[i] = -3;
		else if (command[i] == '<')
			command[i] = -4;
		else if (command[i] == '>')
			command[i] = -5;
		i++;
	}
	if (i)
	{
		tmp = ft_substr(command, 0, i);
		*ret = ft_strjoin_gnl(*ret, tmp);
		free(tmp);
	}
	return (i);
}

char	*quotes(char *command)
{
	char	*ret;
	int		i;

	if (close_quotes(command))
		return (NULL);
	i = before_quotes(command);
	if (!command[i])
		return (command);
	ret = NULL;
	ret = ft_substr(command, 0, i);
	while (command[i])
	{
		i += in_quotes(command + i, &ret);
		i += after_quotes(command + i, &ret);
	}
	free(command);
	return (ret);
}
