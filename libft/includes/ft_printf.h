/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:19:04 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 15:11:55 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

char	*g_str;
char	*g_value;
char	g_percent;
char	g_flag;
int		g_point;
int		g_prec1;
int		g_prec2;
int		g_res;
int		g_error;
va_list	g_arg;

/*
**		MAIN FONCTIONS
*/

int		ft_printf(const char *string, ...);
void	ft_set_element(void);
int		ft_execute(const char **string, char *percent_str, int i, char *hex);

/*
**		GETS FONCTIONS
*/

int		ft_get_element(const char **string);
char	ft_get_first_flag(const char **string);
void	ft_get_first_precision(const char **string);
void	ft_get_second(const char **string);

/*
**		CONVERT FONCTIONS
*/

int		ft_get_i_d(int n, int size, int neg);
int		ft_get_c(int c);
int		ft_get_x(unsigned int n, const char *hex);
int		ft_get_s(char *string);
int		ft_get_i(int n);
int		ft_get_u(int n);
int		ft_get_p(void *pt, char *hex, int i);

/*
**		ADDS FONCTIONS
*/

int		ft_atoi2(const char **str);
int		ft_len_arg(const char *string, va_list arg);
int		ft_len_hex_nbr(unsigned long n);
void	ft_put_unsigned_int(unsigned int n);
int		ft_count(unsigned int n);

#endif
