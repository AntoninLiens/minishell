/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:43:45 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 17:32:11 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					neg;
	unsigned long long	res;
	unsigned long long	res_2;

	neg = 1;
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res_2 = res;
		res = res * 10 + str[i++] - '0';
		if (res > LLONG_MAX || res < res_2)
			return (ft_ternint(neg, -1, 0));
	}
	return ((int)(neg * res));
}
