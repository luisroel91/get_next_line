/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiroel <luiroel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:00:56 by luiroel           #+#    #+#             */
/*   Updated: 2020/02/26 21:17:43 by luiroel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** We need to create two pointers, one that points
** to the pointer that points to alst and another
** to be ablee to cycle through the chain so we can
** iteratively free every item by setting it to ->next
** Should probably use ft_lstdelone instead of rewriting
** the whole "free cycle". Finally we set the pointer to
** alst to NULL
*/

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *palst;
	t_list *temp;

	palst = *alst;
	while (palst)
	{
		temp = palst;
		ft_lstdelone(&palst, del);
		palst = temp->next;
	}
	*alst = NULL;
}
