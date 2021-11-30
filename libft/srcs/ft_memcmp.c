/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:40:17 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 14:54:49 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_bis;
	unsigned char	*s2_bis;

	i = 0;
	s1_bis = (unsigned char *)s1;
	s2_bis = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*s1_bis == *s2_bis && ++i < n)
	{
		s1_bis++;
		s2_bis++;
	}
	return ((int)(*s1_bis - *s2_bis));
}
