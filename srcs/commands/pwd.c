/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:30:27 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/16 00:06:25 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    pwd(t_env *env)
{
	char	*res;

	res = get_env_val(env, "PWD");
	printf("%s\n", res);
	free(res);
}