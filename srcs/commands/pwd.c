/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:30:27 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/31 16:12:49 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int    pwd(t_env *env, char **cmd)
{
	char	*res;

	if (cmd[1])
	{
		printf("pwd: too many arguments\n");
		return (1);
	}
	res = get_env_val(env, "PWD");
	printf("%s\n", res);
	free(res);
	return (0);
}