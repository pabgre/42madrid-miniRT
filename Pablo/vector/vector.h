/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:06:28 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/11 18:21:58 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	float x;
	float y;
	float z;
}				vector;

vector vec(double x, double y, double z);
vector prod(vector u, double lamda);
vector add(vector u, vector v);
vector subs(vector u, vector v);
double dot_prod(vector u, vector v);
vector cross_prod(vector u, vector v);
double magnitude(vector u);
double distance(vector u, vector v);
double angle(vector u, vector v);
#endif
