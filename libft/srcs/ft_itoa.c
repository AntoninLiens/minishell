/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:40:51 by ctirions          #+#    #+#             */
/*   Updated: 2022/01/25 18:43:25 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_itoa_count(int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	if (n < 0)
	{
		count++;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		count++;
		nb /= 10;
	}
	return (++count);
}

char	*ft_itoa(int n)
{
	int				count;
	char			*res;
	unsigned int	nb;

	if (!n)
		return (ft_strdup("0"));
	count = ft_ternint(n, ft_itoa_count(n), 1);
	res = (char *)ft_calloc(sizeof(char), count + 1);
	if (!res)
		return (0);
	nb = ft_ternint(n < 0, -n, n);
	while (count)
	{
		res[count - 1] = nb % 10 + '0';
		if (!(count - 1) && !nb)
			res[count - 1] = '-';
		nb /= 10;
		count--;
	}
	return (res);
}
