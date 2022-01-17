/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:24:09 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/17 18:06:09 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	set_sig_cmd_in(t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->heredoc)
			return (sig_cmd_heredoc_in());
		tmp = tmp->next;
	}
	return (sig_cmd_in());
}

int	sig_cmd_heredoc_in(void)
{
	signal(SIGINT, &ctrl_c_cmd_heredoc_in);
	return (1);
}

int	sig_cmd_in(void)
{
	signal(SIGINT, &ctrl_c_cmd_in);
	return (1);
}

void	ctrl_c_cmd_heredoc_in(int code)
{
	(void)code;
	usleep(88);
	exit(130);
}

void	ctrl_c_cmd_in(int code)
{
	(void)code;
	exit(130);
}
