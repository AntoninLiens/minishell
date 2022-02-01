/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:47:24 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/01 16:36:00 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	aff_env(t_env *env, char **cmd)
{
	t_env	*tmp;

	if (cmd[1])
	{
		ft_putstr_fd("env: too many arguments\n", STDERR_FILENO);
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
