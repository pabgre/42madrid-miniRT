/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:01:58 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/12 18:08:21 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *aux;

	aux = *alst;
	if (alst == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	if (aux != NULL)
	{
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = new;
	}
}
