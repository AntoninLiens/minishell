/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:24:09 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/16 18:05:22 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_sig_cmd_in(t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->heredoc)
		{
			sig_cmd_heredoc_in();
			return ;
		}
		tmp = tmp->next;
	}
	sig_cmd_in();
}

int	sig_cmd_heredoc_in(void)
{
	signal(SIGINT, &ctrl_c_cmd_heredoc_in);
	return (1);
}

void	sig_cmd_in(void)
{
	signal(SIGINT, &ctrl_c_cmd_in);
}

void	ctrl_c_cmd_heredoc_in(int code)
{
	(void)code;
	write(2, "", 1);
	exit(1);
}

void	ctrl_c_cmd_in(int code)
{
	(void)code;
	exit(1);
}
