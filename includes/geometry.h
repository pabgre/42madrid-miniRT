/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <npinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:00:47 by pabgre            #+#    #+#             */
/*   Updated: 2020/07/15 11:47:59 by npinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "vector.h"
# include <stdbool.h>
# include "color.h"

typedef enum	e_geometry{
	NONE, SPHERE, CYLINDER, PLANE, CUBE, TRIANGLE, CONE
}				t_geometry;

typedef struct	s_sphere
{
	t_vector	center;
	double		radius;
	t_color		color;
}				t_sphere;

typedef struct	s_cylinder
{
	t_vector	dir;
	t_vector	center;
	double		radius;
	double		height;
	t_color		color;
}				t_cylinder;

typedef struct	s_line
{
	t_vector	point;
	t_vector	dir;
}				t_line;

typedef struct	s_m_plane
{
	t_vector	point;
	t_vector	normal;
	t_color		color;
}				t_m_plane;

typedef struct	s_triangle
{
	t_vector	point_a;
	t_vector	point_b;
	t_vector	point_c;
	t_color		color;
}				t_triangle;

typedef struct	s_3d_obj
{
	void		*obj;
	t_geometry	type;
}				t_3d_obj;

typedef struct	s_ray_hit_data
{
	t_vector	hit_point;
	t_geometry	hit_object;
	t_vector	normal;
	t_color		color;
}				t_ray_hit_data;

t_line		l(t_vector dir, t_vector origin);
t_m_plane		pl(t_vector normal, t_vector point);
t_vector closest_point_line(t_vector point, t_line my_line);
double dist_point_line(t_vector point, t_line my_line);
bool which_is_near(t_vector pt_a, t_vector pt_b, t_vector origin);
t_vector	closest_point(t_vector point_a, t_vector point_b, t_vector origin);
t_vector line_plane_intersection(t_line line, t_m_plane plane);
t_ray_hit_data sphere_hit_point(t_line ray, t_sphere sphere);
t_ray_hit_data	cylinder_hit_point(t_line ray, t_cylinder cylinder);
t_ray_hit_data	ray_hit_triangle(t_line ray, t_triangle triangle);
t_ray_hit_data	ray_hit_math_plane(t_line ray, t_m_plane plane);
bool		is_in_positive_plane_side(t_vector point, t_m_plane pl);
#endif
