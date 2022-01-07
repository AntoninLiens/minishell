/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:47:24 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/08 00:26:04 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	aff_env(t_env *env, char **cmd)
{
	t_env	*tmp;

	if (cmd[1])
	{
		printf("env: too many arguments\n");
		return (127);
	}
	tmp = env;
	while (tmp)
	{
		printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
	return (0);
}
