/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:07:29 by aliens            #+#    #+#             */
/*   Updated: 2021/12/30 12:11:26 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main_init(t_mini *shell)
{
	shell->basic_env = env;
	shell->exit = 0;
	if (init_env(shell, shell->basic_env))
		return (1);
	up_shlvl(shell);
	return (0);
}