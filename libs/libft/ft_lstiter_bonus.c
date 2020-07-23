/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:27:57 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/12 18:09:10 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *thisnode;

	thisnode = lst;
	while (thisnode != NULL)
	{
		f(thisnode->content);
		thisnode = thisnode->next;
	}
}
