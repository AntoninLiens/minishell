/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:16:08 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/22 15:31:05 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	len = ft_strlen((char *)s);
	while (len--)
		if (s[len] == c)
			return ((char *)s + len);
	return (0);
}
