/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:06:28 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/31 11:32:08 by psan-gre         ###   ########.fr       */
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

typedef struct	s_vector2_int
{
	int x;
	int y;
}				t_vector2_int;

typedef struct	s_vector2_double
{
	double x;
	double y;
}				t_vector2_double;

t_vector		vec(double x, double y, double z);
t_vector		prod(t_vector u, double lamda);
t_vector		add(t_vector u, t_vector v);
t_vector		subs(t_vector u, t_vector v);
double			dot_prod(t_vector u, t_vector v);
t_vector		cross_prod(t_vector u, t_vector v);
double			magnitude(t_vector u);
double			distance(t_vector u, t_vector v);
double			angle(t_vector u, t_vector v);
t_vector		normalize(t_vector u);
t_vector		rotate(t_vector u, t_vector axis, double theta);
t_vector2_int	vec2_int(int x, int y);
#endif
