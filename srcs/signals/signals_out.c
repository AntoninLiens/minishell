/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:22 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/17 14:35:41 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	set_sig_cmd_out(t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->heredoc)
			return (sig_cmd_heredoc_out());
		tmp = tmp->next;
	}
	return (sig_cmd_out());
}

int	sig_cmd_heredoc_out(void)
{
	signal(SIGINT, &ctrl_c_cmd_heredoc_out);
	return (1);
}

int	sig_cmd_out(void)
{
	signal(SIGINT, &ctrl_c_cmd_out);
	return (1);
}

void	ctrl_c_cmd_heredoc_out(int code)
{
	(void)code;
	usleep(88);
	write(2, "\n", 2);
}

void	ctrl_c_cmd_out(int code)
{
	(void)code;
	write(2, "\n", 1);
}
