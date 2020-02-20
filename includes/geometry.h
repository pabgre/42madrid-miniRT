/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:00:47 by pabgre            #+#    #+#             */
/*   Updated: 2020/02/20 17:31:48 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "vector.h"
# include <stdbool.h>
# include "color.h"

typedef enum e_geometry{
	NONE, SPHERE, CYLINDER, PLANE, CUBE, TRIANGLE, CONE
}				t_geometry;

typedef struct s_sphere
{
	t_vector center;
	double radius;
	t_color color;
}				t_sphere;

typedef struct s_cylinder
{
	t_vector dir;
	t_vector center;
	double radius;
	double height;
	t_color color;
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
	t_color color;
}				t_plane;

typedef struct s_triangle
{
    t_vector point_a;
    t_vector point_b;
    t_vector point_c;
	t_color color;
}               t_triangle;

typedef struct	s_ray_hit_data
{
	t_vector	hit_point;
	t_geometry	hit_object;
	t_color		color;
}				t_ray_hit_data;

t_vector closest_point_line(t_vector point, t_line my_line);
double dist_point_line(t_vector point, t_line my_line);
double dist_point_plane(t_vector point, t_plane my_plane);
double	ray_hit_sphere(t_line ray, t_sphere sphere);
t_ray_hit_data sphere_hit_point(t_line ray, t_sphere sphere);
double		ray_hit_cylinder(t_line ray, t_cylinder cylinder);
t_ray_hit_data	cylinder_hit_point(t_line ray, t_cylinder cylinder);
#endif
