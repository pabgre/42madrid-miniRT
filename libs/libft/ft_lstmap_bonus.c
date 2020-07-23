/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:47:04 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/12 18:09:19 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *out;
	t_list *out_aux;
	t_list *lst_aux;

	lst_aux = lst;
	out = NULL;
	if (lst_aux != NULL)
	{
		if ((out = (t_list*)malloc(sizeof(t_list))))
		{
			out_aux = out;
			while (out_aux != NULL && lst_aux != NULL)
			{
				out_aux->content = f(lst_aux->content);
				if ((out_aux->next = (t_list*)malloc(sizeof(t_list))))
				{
					out_aux = out_aux->next;
					lst_aux = lst_aux->next;
				}
				else
					ft_lstclear(&out, del);
			}
		}
	}
	return (out);
}
