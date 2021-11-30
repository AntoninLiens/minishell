/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:30:11 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 17:23:01 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;

	pt = (char *)malloc(count * size * sizeof(void));
	if (!pt)
		return (0);
	ft_bzero(pt, count * size);
	return ((void *)pt);
}
