/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:19:42 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/31 16:27:34 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	echo(char **cmd)
{
    int     i;
	int		tmp;
	int		no_backslash;

    i = 1;
	no_backslash = 0;
	if (cmd[1][0] == '-')
	{
		no_backslash = 1;
		i++;
	}
    if (cmd[i][0] == '\"')
    {
    	cmd[i]++;
		tmp = i - 1;
		while (cmd[++tmp])
			if (cmd[tmp][ft_strlen(cmd[tmp]) - 1] == '\"')
				cmd[tmp][ft_strlen(cmd[tmp]) - 1] = '\0';
    }
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
