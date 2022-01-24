/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:11:00 by aliens            #+#    #+#             */
/*   Updated: 2022/01/24 16:31:56 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*quotes(char *command, t_cmd *cmd)
{
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
		printf("%c\n", command[i]);
		if (command[i] == '\'' || command[i] == '\"')
		{
			if (command[i] == '\'')
				cmd->s_quotes++;
			else
				cmd->d_quotes++;
			j = 1;	
			while (command[i + j] != command[i])
				j++;
			ret = ft_strjoin(ret, ft_substr(command, i + 1, j - 1));
			i += j + 1;
		}
		j = 0;
		while (command[i + j] && \
		command[i + j] != '\"' && command[i + j] != '\'')
			j++;
		if (j)
			ret = ft_strjoin(ret, ft_substr(command, i, j));
		i += j;
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
