/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@students.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 01:28:53 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/16 15:03:32 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    sigint(int code)
{
    (void)code;
    ft_putstr_fd("\b\b   ", STDERR_FILENO);
    printf("\nMINISHELL $ ");
}