/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 05:16:30 by zminhas           #+#    #+#             */
/*   Updated: 2022/01/29 05:16:55 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	lst_first(t_cmd **list)
{
	if (list && *list)
		while ((*list)->prev)
			*list = (*list)->prev;
}

void	lst_last(t_cmd **list)
{
	if (list && *list)
		while ((*list)->next)
			*list = (*list)->next;
}
