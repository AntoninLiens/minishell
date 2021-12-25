/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:47:51 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/25 18:00:49 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*pt;

	pt = (char *)ft_calloc(sizeof(char), \
					(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!pt)
		return (0);
	i = -1;
	while (s1 && s1[++i])
		pt[i] = s1[i];
	i -= 1;
	while (s2 && s2[++i - ft_strlen(s1)])
		pt[i] = s2[i - ft_strlen(s1)];
	return (pt);
}
