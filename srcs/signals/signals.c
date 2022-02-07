/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:55:35 by aliens            #+#    #+#             */
/*   Updated: 2022/02/07 13:56:46 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	set_sig_cmd_in(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->heredoc)
			return (sig_cmd_heredoc_in());
		tmp = tmp->next;
	}
	return (sig_cmd_in());
}

int	set_sig_cmd_out(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->heredoc)
			return (sig_cmd_heredoc_out());
		tmp = tmp->next;
	}
	return (sig_cmd_out());
}
