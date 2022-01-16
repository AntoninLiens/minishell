/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:22 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/16 18:05:53 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_sig_cmd_out(t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->heredoc)
		{
			sig_cmd_heredoc_out();
			return ;
		}
		tmp = tmp->next;
	}
	sig_cmd_out();
}

void	sig_cmd_heredoc_out(void)
{
	signal(SIGINT, &ctrl_c_cmd_heredoc_out);
}

void	sig_cmd_out(void)
{
	signal(SIGINT, &ctrl_c_cmd_out);
}

void	ctrl_c_cmd_heredoc_out(int code)
{
	(void)code;
	write(2, "", 1);
	write(2, "\n", 1);
}

void	ctrl_c_cmd_out(int code)
{
	(void)code;
	write(2, "\n", 1);
}
