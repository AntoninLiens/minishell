/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:20:39 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 18:20:09 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_flag_bef(int size, int neg)
{
	int	i;

	i = 0;
	if (g_flag == '*')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	if (neg)
		ft_putchar_fd('-', 1);
	if (g_flag == '0')
		while (i++ < g_prec1 - size)
			write(1, "0", 1);
	return (i);
}

static int	ft_weird_i_d(unsigned int n, int k, int i, int neg)
{
	int	size;
	int	l;
	int	j;

	size = ft_ternint(g_point, g_prec2, g_prec1);
	l = ft_ternint(!size && !n, 1, 0);
	size = ft_ternint(size > ft_count(n), size, ft_count(n));
	i += k;
	j = 0;
	if (g_flag == '*' || g_flag == '0')
		while (-l + i++ < g_prec1 - size - neg)
			write(1, " ", 1);
	if (neg)
		ft_putchar_fd('-', 1);
	while (j++ < size - ft_count(n))
		write(1, "0", 1);
	if (l)
		size--;
	else
		ft_put_unsigned_int(n);
	if (g_flag == '-')
		while (i++ < g_prec1 - size - neg)
			write(1, " ", 1);
	return (ft_ternint(i, size + i - 1 + neg, size + neg));
}

int	ft_get_i_d(int n, int size, int neg)
{
	int				i;
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = -n;
		neg++;
	}
	else
		nbr = n;
	if (g_flag == '.' || g_point)
		return (ft_weird_i_d(nbr, size, 0, neg));
	size += ft_count(nbr) + neg;
	i = ft_flag_bef(size, neg);
	ft_put_unsigned_int(nbr);
	if (g_flag == '-')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	return (ft_ternint(i, size + i - 1, size));
}
