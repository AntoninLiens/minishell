/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:19:42 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/24 17:19:16 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	echo(char **cmd)
{
    int     i;
	int		tmp;
	int		no_backslash;

	if (!cmd[1])
	{
		printf("\n");
		return (0);
	}
    i = 1;
	no_backslash = 0;
	while (cmd[i] && !ft_strncmp(cmd[i], "-n", 2))
	{
		tmp = 0;
		while (cmd[i][++tmp])
		{
			if (cmd[i][tmp] != 'n' || cmd[i][0] != '-')
			{
				tmp = -1;
				break ;
			}
		}
		if (tmp == -1)
			break ;
		no_backslash = 1;
		i++;
	}
	if (!cmd[i])
		return (0);
    while (cmd[i])
	{
    	printf("%s", cmd[i++]);
		if (cmd[i])
			printf(" ");
	}
	if (!no_backslash)
		printf("\n");
	return (0);
}
