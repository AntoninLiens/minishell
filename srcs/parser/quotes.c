/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:11:00 by aliens            #+#    #+#             */
/*   Updated: 2022/01/24 19:43:38 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*quotes(char *command)
{
	char	*tmp;
	char	*ret;
	int		i;
	int		j;

	ret = NULL;
	i = 0;
	while (command[i] && command[i] != '\"' && command[i] != '\'')
		i++;
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
				if (command[i + j] == ' ')
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
