/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:52:27 by aliens            #+#    #+#             */
/*   Updated: 2022/02/08 14:12:32 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signals_default(void)
{
	signal(SIGQUIT, &sigquit);
	signal(SIGINT, &sigint);
}

int	sig_cmd_heredoc_in(void)
{
	signal(SIGINT, &sigint_cmd_heredoc_in);
	signal(SIGQUIT, &sigquit_cmd_heredoc_in);
	return (1);
}

int	sig_cmd_heredoc_out(void)
{
	signal(SIGQUIT, &sigquit_cmd_heredoc_out);
	signal(SIGINT, &sigint_cmd_heredoc_out);
	return (1);
}

int	sig_cmd_in(void)
{
	signal(SIGQUIT, &sigquit_cmd_in);
	signal(SIGINT, &sigint_cmd_in);
	return (1);
}

int	sig_cmd_out(void)
{
	signal(SIGQUIT, &sigquit_cmd_out);
	signal(SIGINT, &sigint_cmd_out);
	return (1);
}
