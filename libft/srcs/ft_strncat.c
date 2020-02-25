/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiroel <luiroel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:08:05 by luiroel           #+#    #+#             */
/*   Updated: 2020/02/20 16:39:50 by luiroel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*str;

	str = s1 + ft_strlen(s1);
	while (*s2 != '\0' && n)
	{
		*str++ = *s2++;
		n--;
	}
	*str = '\0';
	return (s1);
}
