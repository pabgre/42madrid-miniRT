/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:00:47 by pabgre            #+#    #+#             */
/*   Updated: 2020/02/17 13:44:40 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "vector.h"
# include <stdbool.h>

typedef enum e_geometry{
	NONE, SPHERE, CYLINDER, PLANE, CUBE, TRIANGLE, CONE
}				t_geometry;

typedef struct s_sphere
{
	t_vector center;
	double radius;
}				t_sphere;

typedef struct s_cylinder
{
	t_vector a_point;;
	t_vector b_point;
	double radius;
}				t_cylinder;

typedef struct s_line
{
	t_vector point;
	t_vector dir;
}				t_line;

typedef struct s_plane
{
	t_vector point;
	t_vector normal;
}				t_plane;

typedef struct s_triangle
{
    t_vector point_a;
    t_vector point_b;
    t_vector point_c;
}               t_triangle;

t_vector closest_point_line(t_vector point, t_line my_line);
double dist_point_line(t_vector point, t_line my_line);
double dist_point_plane(t_vector point, t_plane my_plane);
bool is_point_in_sphere(t_vector point, t_sphere my_sphere);
bool is_point_in_cylinder(t_vector point, t_cylinder my_cylinder);
bool is_point_in_plane(t_vector point, t_plane my_plane, double epsilon);
bool is_point_in_triangle(t_vector point, t_triangle my_triangle, double epsilon);
#endif
