/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:56:00 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/12 18:09:15 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *aux;

	aux = lst;
	if (!lst)
	{
		return (NULL);
	}
	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	return (aux);
}
