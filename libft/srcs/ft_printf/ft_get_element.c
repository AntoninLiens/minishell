/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:37:40 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/22 15:38:42 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	ft_get_first_flag(const char **string)
{
	char	*flags;
	int		i;

	i = -1;
	flags = "-0.";
	if ((ft_isdigit((int)**string) && **string != '0') || **string == '*')
		return ('*');
	while (flags[++i])
	{
		if (**string == flags[i])
		{
			(*string)++;
			if (i == 0 || i == 1)
			{
				while (**string == '-' || **string == '0')
				{
					i = ft_ternint(i && **string == '-', i - 1, i);
					(*string)++;
				}
			}
			return (flags[i]);
		}
	}
	return (0);
}

void	ft_get_first_precision(const char **string)
{
	if (!ft_strchr(".*sicxXupd%", (int)**string) && \
		!ft_isdigit((int)**string) && **string != '-')
	{
		g_error = 1;
		return ;
	}
	else if (**string == '*')
	{
		g_prec1 = va_arg(g_arg, int);
		(*string)++;
	}
	else if (ft_isdigit((int)**string) || **string == '-')
		g_prec1 = ft_atoi2(string);
}

void	ft_get_second(const char **string)
{
	if (ft_strchr("sicxXupd%", (int)**string))
		return ;
	else if (**string != '.')
	{
		g_error = 1;
		return ;
	}
	g_point = 1;
	(*string)++;
	if (**string == '*')
	{
		g_prec2 = va_arg(g_arg, int);
		(*string)++;
	}
	else if (ft_isdigit((int)**string))
		g_prec2 = ft_atoi2(string);
}

int	ft_execute(const char **string, char *percent_str, int i, char *hex)
{
	while (percent_str[++i])
	{
		if (**string == percent_str[i])
		{
			if (i == 0)
				return (ft_get_s(va_arg(g_arg, char *)));
			else if (i == 1 || i == 7)
				return (ft_get_i_d(va_arg(g_arg, int), 0, 0));
			else if (i == 2)
				return (ft_get_c(va_arg(g_arg, int)));
			else if (i == 3)
				return (ft_get_x(va_arg(g_arg, unsigned int), hex));
			else if (i == 4)
				return (ft_get_x(va_arg(g_arg, unsigned int), \
					"0123456789ABCDEF"));
			else if (i == 5)
				return (ft_get_u(va_arg(g_arg, int)));
			if (i == 6)
				return (ft_get_p(va_arg(g_arg, void *), hex, 0));
			return (ft_get_c('%'));
		}
	}
	g_error = 1;
	return (0);
}
