/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:19:42 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/21 15:41:06 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    echo(char *cmd)
{
	char	**arg;
    int     i;
	int		tmp;
	int		no_backslash;

    i = 1;
	no_backslash = 0;
	arg = ft_split(cmd, ' ');
	if (arg[1][0] == '-' && arg[1][1] == 'n')
	{
		no_backslash = 1;
		i++;
	}
    if (arg[i][0] == '\"')
    {
    	arg[i]++;
		tmp = i - 1;
		while (arg[++tmp])
			if (arg[tmp][ft_strlen(arg[tmp]) - 1] == '\"')
				arg[tmp][ft_strlen(arg[tmp]) - 1] = '\0';
    }
    while (arg[i])
	{
    	printf("%s", arg[i++]);
		if (arg[i])
			printf(" ");
	}
	if (!no_backslash)
		printf("\n");
}
