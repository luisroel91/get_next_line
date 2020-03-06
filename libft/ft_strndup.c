/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiroel <luiroel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:43:57 by luiroel           #+#    #+#             */
/*   Updated: 2020/03/06 14:44:07 by luiroel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = ft_strnew(size)))
	{
		return (NULL);
	}
	while (s1[i] && i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
