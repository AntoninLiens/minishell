/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:23:20 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 18:41:58 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_flag_zero_all(int size, int l, int weird)
{
	int	i;

	i = 0;
	if (g_flag == '*')
		while (-l + i++ < g_prec1 - size)
			write(1, " ", 1);
	else if (g_flag == '0')
	{
		while (-l + i++ < g_prec1 - size)
		{
			if (weird)
				write(1, " ", 1);
			else
				write(1, "0", 1);
		}
	}
	return (i);
}

static void	ft_weird_x2(int l, int *size, char *res)
{
	if (l)
		(*size)--;
	else
		ft_putstr_fd(res, 1);
	free(res);
}

static int	ft_weird_x(unsigned int n, const char *hex, int power, char *res)
{
	int	size;
	int	i;
	int	l;
	int	j;

	size = ft_ternint(g_point, g_prec2, g_prec1);
	l = ft_ternint(!n && !size, 1, 0);
	size = ft_ternint(size > power, size, power);
	j = 0;
	i = ft_flag_zero_all(size, l, 1);
	while (j++ < size - power)
		write(1, "0", 1);
	while (power--)
	{
		res[power] = hex[n % 16];
		n /= 16;
	}
	ft_weird_x2(l, &size, res);
	if (g_flag == '-')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	return (ft_ternint(i, size + i - 1, size));
}

int	ft_get_x(unsigned int n, const char *hex)
{
	int		i;
	int		power;
	int		size;
	char	*res;

	i = 0;
	power = ft_len_hex_nbr(n);
	size = power;
	res = (char *)ft_calloc(sizeof(char), power + 1);
	if (!res)
		return (0);
	if (g_flag == '.' || g_point)
		return (ft_weird_x(n, hex, power, res));
	i = ft_flag_zero_all(size, 0, 0);
	while (power--)
	{
		res[power] = hex[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	free(res);
	if (g_flag == '-')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	return (ft_ternint(i, size + i - 1, size));
}
