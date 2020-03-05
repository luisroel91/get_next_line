/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiroel <luiroel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:59:09 by luiroel           #+#    #+#             */
/*   Updated: 2020/03/03 15:05:45 by luiroel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int		number;
	char	**str;
	int		i;
	int		j;
	int		start;

	if (!s || !c)
		return (NULL);
	number = ft_countwords(s, c);
	if (!(str = malloc((sizeof(char *) * (number + 1)))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < number)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		str[j] = ft_strsub(s, start, i - start);
		i++;
	}
	str[j] = NULL;
	return (str);
}
