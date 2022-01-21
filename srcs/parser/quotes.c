/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:11:00 by aliens            #+#    #+#             */
/*   Updated: 2022/01/21 19:16:50 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*s_quotes(char *command, t_cmd *cmd, int *i)
{
	int	j;
	char *ret;
	
	j = 1;
	cmd->s_quotes++;
	ret = ft_substr(command, 0, *i);
	while(command[*i + j] && command[*i + j] != command[*i])
		j++;
	ret = ft_strjoin(ret, ft_substr(command, *i + 1, j - 1));
	*i += j;
	j = 0;
	while (command[*i + j])
		j++;
	ret = ft_strjoin(ret, ft_substr(command, *i + 1, j));
	return (ret);
}

char	*d_quotes(char *command, t_cmd *cmd, int *i)
{
	int	j;
	char *ret;

	j = 1;
	cmd->d_quotes++;
	ret = ft_substr(command, 0, *i);
	while(command[*i + j] && command[*i + j] != command[*i])
		j++;
	ret = ft_strjoin(ret, ft_substr(command, *i + 1, j - 1));
	*i += j;
	j = 0;
	while (command[*i + j])
		j++;
	ret = ft_strjoin(ret, ft_substr(command, *i + 1, j));
	return (ret);
}

char	*quotes(char *command, t_cmd *cmd)
{
	char	*ret;
	int		i;

	i = -1;
	ret = NULL;
	while (command[++i])
	{
		if (command[i] == '\'')
			ret = s_quotes(command, cmd, &i);
		if (command[i] == '\"')
			ret = d_quotes(command, cmd, &i);
	}
	if (!ret)
		return (command);
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