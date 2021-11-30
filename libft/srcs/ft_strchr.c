/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:11:03 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/22 15:28:25 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)s + i);
	return (0);
}
