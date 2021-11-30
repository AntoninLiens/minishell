/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:28:19 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 17:38:44 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_bis;

	s_bis = (unsigned char *)s;
	i = -1;
	while (n--)
		if (s_bis[++i] == (unsigned char)c)
			return ((void *)s + i);
	return (0);
}
