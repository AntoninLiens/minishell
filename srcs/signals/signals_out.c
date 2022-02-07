/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:22 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/07 14:16:55 by aliens           ###   ########.fr       */
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
