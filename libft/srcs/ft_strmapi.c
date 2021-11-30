/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:09:30 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/22 15:30:10 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (!s || !f)
		return (0);
	i = -1;
	res = (char *)ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!res)
		return (0);
	while (++i < ft_strlen(s))
		res[i] = f(i, s[i]);
	return (res);
}
