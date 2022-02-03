/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_defaults.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 01:28:53 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/03 16:26:22 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigquit(int code)
{
	(void)code;
	rl_on_new_line();
	rl_redisplay();
}

void	sigint(int code)
{
	if (code != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_on_new_line();
	//rl_replace_line("", 0);
	rl_redisplay();
}

void	ctrl_c_default(void)
{
	signal(SIGQUIT, &sigquit);
	signal(SIGINT, &sigint);
}
