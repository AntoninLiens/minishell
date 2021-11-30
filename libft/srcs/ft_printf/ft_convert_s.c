/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:22:09 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 18:20:27 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_flag_zero_all(int size)
{
	int	i;

	i = 0;
	if (g_flag == '*')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	else if (g_flag == '0')
		while (i++ < g_prec1 - size)
			write(1, "0", 1);
	return (i);
}

static int	ft_weird_s(char *str, char *str2)
{
	int		size;
	int		size2;
	int		i;
	int		j;

	size = ft_ternint(g_point, g_prec2, g_prec1);
	size2 = ft_ternint(!str, 6, ft_strlen(str));
	size = ft_ternint(size > size2, size2, size);
	i = 0;
	j = ft_flag_zero_all(size);
	if (!str)
		while (str2[i] && i < size)
			ft_putchar_fd(str2[i++], 1);
	else
		while (str[i] && i < size)
			ft_putchar_fd(str[i++], 1);
	if (g_flag == '-')
		while (j++ < g_prec1 - size)
			write(1, " ", 1);
	j = ft_ternint(j, j - 1, j);
	return (size + j);
}

int	ft_get_s(char *str)
{
	int	size;
	int	i;

	if (g_flag == '.' || g_point)
		return (ft_weird_s(str, "(null)"));
	size = ft_ternint(!str, 6, ft_strlen(str));
	i = ft_flag_zero_all(size);
	if (!str)
		write(1, "(null)", 6);
	else
		ft_putstr_fd(str, 1);
	if (g_flag == '-')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	i = ft_ternint(i, i - 1, i);
	return (ft_ternint(!str, 6 + i, ft_strlen(str) + i));
}
