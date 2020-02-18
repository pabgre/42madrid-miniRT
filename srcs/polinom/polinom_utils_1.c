/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polinom_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:49:23 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/18 18:00:02 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/polinom.h"

t_polinom2	poli(double a, double b, double c)
{
	t_polinom2	pol;

	pol.a = a;
	pol.b = b;
	pol.c = c;

	return (pol);
}

double		discr(t_polinom2 pol)
{
	return (pol.b * pol.b - 4 * pol.a * pol.c);
}

