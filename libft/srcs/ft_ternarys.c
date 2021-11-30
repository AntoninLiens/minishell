/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternarys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:33:35 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/22 15:32:10 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_ternint(int boolean, int a, int b)
{
	if (boolean)
		return (a);
	return (b);
}

char	ft_ternchar(int boolean, char a, char b)
{
	if (boolean)
		return (a);
	return (b);
}

unsigned long	ft_ternul(int boolean, unsigned long a, unsigned long b)
{
	if (boolean)
		return (a);
	return (b);
}
