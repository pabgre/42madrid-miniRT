/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:06:28 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/25 17:13:33 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

t_vector vec(double x, double y, double z);
t_vector prod(t_vector u, double lamda);
t_vector add(t_vector u, t_vector v);
t_vector subs(t_vector u, t_vector v);
double dot_prod(t_vector u, t_vector v);
t_vector cross_prod(t_vector u, t_vector v);
double magnitude(t_vector u);
double distance(t_vector u, t_vector v);
double angle(t_vector u, t_vector v);
t_vector normalize(t_vector u);
#endif
