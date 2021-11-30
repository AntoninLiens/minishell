/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:13:45 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 14:56:00 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s_size;
	size_t	d_size;

	i = 0;
	s_size = 0;
	d_size = 0;
	while (src[s_size])
		s_size++;
	if (!dstsize)
		return (s_size);
	while (d_size < dstsize && dst[d_size])
		d_size++;
	if (dstsize <= d_size)
		return (dstsize + s_size);
	while (dstsize && (--dstsize - d_size) && src[i])
	{
		dst[d_size + i] = src[i];
		i++;
	}
	dst[d_size + i] = 0;
	return (s_size + d_size);
}
