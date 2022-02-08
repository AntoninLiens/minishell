/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:22 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/08 15:09:03 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigint_cmd_heredoc_out(int code)
{
	(void)code;
	usleep(88);
	write(STDERR_FILENO, "\n", 2);
}

void	sigquit_cmd_out(int code)
{
	(void)code;
	write(STDERR_FILENO, "Quit: 3\n", 8);
}

void	sigint_cmd_out(int code)
{
	(void)code;
	write(STDERR_FILENO, "\n", 1);
}

void	sigquit_cmd_heredoc_out(int code)
{
	(void)code;
	printf("\r");
}
