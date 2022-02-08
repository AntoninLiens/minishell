/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:24:09 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/08 14:22:44 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigint_cmd_heredoc_in(int code)
{
	(void)code;
	usleep(88);
	exit(130);
}

void	sigint_cmd_in(int code)
{
	(void)code;
	exit(130);
}

void	sigquit_cmd_in(int code)
{
	(void)code;
	rl_replace_line("", 0);
	exit(131);
}

void	sigquit_cmd_heredoc_in(int code)
{
	(void)code;
	rl_on_new_line();
	rl_redisplay();
}

