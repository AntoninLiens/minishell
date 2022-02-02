/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:16:08 by zminhas           #+#    #+#             */
/*   Updated: 2022/02/02 16:16:33 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unset(t_env *env, char *name)
{
	t_env	*tmp;
	t_env	*tmp2;

	tmp = env;
	if (!ft_strncmp("_", name, 2))
		return ;
	if (!ft_strncmp(tmp->str, name, ft_strlen(name)))
	{
		env = env->next;
		free(tmp->str);
		free(tmp);
		return ;
	}
	while (tmp->next)
	{
		if (!ft_strncmp(tmp->next->str, name, ft_strlen(name)))
		{
			tmp2 = tmp->next->next;
			free(tmp->next->str);
			free(tmp->next);
			tmp->next = tmp2;
			return ;
		}
		tmp = tmp->next;
	}
}
