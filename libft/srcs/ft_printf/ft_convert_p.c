/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:21:25 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 18:20:17 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	ft_putres(unsigned long addr, int power, char *hex, char *res)
{
	while (power--)
	{
		res[power] = hex[addr % 16];
		addr /= 16;
	}
	ft_putstr_fd(res, 1);
	free(res);
}

static int	ft_weird_p(unsigned long addr, int power, char *hex, char *res)
{
	int	size;
	int	i;
	int	j;
	int	l;

	j = 0;
	i = 0;
	size = ft_ternint(g_point, g_prec2, g_prec1);
	l = ft_ternint(!size && !addr, 1, 0);
	size = ft_ternint(size > power, size, power);
	if (g_flag == '*' || g_flag == '0')
		while (i++ < g_prec1 - size - 2 + l)
			write(1, " ", 1);
	write(1, "0x", 2);
	while (j++ < size - power)
		write(1, "0", 1);
	if (l)
		size--;
	else
		ft_putres(addr, power, hex, res);
	if (g_flag == '-')
		while (i++ < g_prec1 - size - 2)
			write(1, " ", 1);
	i = ft_ternint(i, i - 1, i);
	return (size + 2 + i);
}

static int	ft_get_p2(int size)
{
	int	i;

	i = 0;
	if (g_flag == '*')
		while (i++ < g_prec1 - size - 2)
			write(1, " ", 1);
	write(1, "0x", 2);
	if (g_flag == '0')
		while (i++ < g_prec1 - size - 2)
			write(1, "0", 1);
	return (i);
}

int	ft_get_p(void *pt, char *hex, int i)
{
	unsigned long	addr;
	int				power;
	int				size;
	char			*res;

	addr = (unsigned long)pt;
	power = ft_len_hex_nbr(addr);
	res = (char *)ft_calloc(sizeof(char), power + 1);
	if (!res)
		return (0);
	if (g_point || g_flag == '.')
		return (ft_weird_p(addr, power, hex, res));
	size = power;
	i = ft_get_p2(size);
	ft_putres(addr, power, hex, res);
	if (g_flag == '-')
		while (i++ < g_prec1 - size - 2)
			write(1, " ", 1);
	i = ft_ternint(i, i - 1, i);
	return (size + 2 + i);
}
