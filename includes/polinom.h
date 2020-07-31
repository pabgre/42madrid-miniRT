/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polinom.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:49:27 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/31 11:32:02 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLINOM_H
# define POLINOM_H

typedef struct	s_polinom2
{
	double a;
	double b;
	double c;
}				t_polinom2;
t_polinom2		poli(double a, double b, double c);
double			discr(t_polinom2 pol);
#endif
