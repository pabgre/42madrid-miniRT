/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:21:16 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/12 18:09:01 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *thisnode;
	t_list *nextnode;

	thisnode = *lst;
	*lst = NULL;
	while (thisnode != NULL)
	{
		nextnode = thisnode->next;
		ft_lstdelone(thisnode, del);
		thisnode = nextnode;
	}
}
