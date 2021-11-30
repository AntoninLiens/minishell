/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:22:51 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 18:25:10 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_weird_u(unsigned int nbr, int l)
{
	int	size;
	int	i;
	int	j;

	size = ft_ternint(g_point, g_prec2, g_prec1);
	l = ft_ternint(!nbr && !size, 1, 0);
	size = ft_ternint(size > ft_count(nbr), size, ft_count(nbr));
	i = 0;
	j = 0;
	if (g_flag == '*')
		while (-l + i++ < g_prec1 - size)
			write(1, " ", 1);
	else if (g_flag == '0')
		while (-l + i++ < g_prec1 - size)
			write(1, " ", 1);
	while (j++ < size - ft_count(nbr))
		write(1, "0", 1);
	if (l)
		size--;
	else
		ft_put_unsigned_int(nbr);
	if (g_flag == '-')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	return (ft_ternint(i, size + i - 1, size));
}

int	ft_get_u(int n)
{
	unsigned int	nbr;
	int				size;
	int				i;

	if (n < 0)
		nbr = UINT_MAX + n + 1;
	else
		nbr = n;
	if (g_flag == '.' || g_point)
		return (ft_weird_u(nbr, 0));
	size = ft_count(nbr);
	i = 0;
	if (g_flag == '*')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	else if (g_flag == '0')
		while (i++ < g_prec1 - size)
			write(1, "0", 1);
	ft_put_unsigned_int(nbr);
	if (g_flag == '-')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	return (ft_ternint(i, size + i - 1, size));
}
