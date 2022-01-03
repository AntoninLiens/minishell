/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:48:15 by aliens            #+#    #+#             */
/*   Updated: 2022/01/03 16:10:33 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int init(t_mini *shell, char **env)
{
	shell->basic_env = env;
	shell->exit = 0;
	if (init_env(shell, env))
		return (1);
	up_shlvl(shell);
    return (0);
}