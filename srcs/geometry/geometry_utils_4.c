/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:24:44 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/21 12:48:01 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"
#include "../../includes/raytracer.h"

t_ray_hit_data	ray_hit_plane(t_line ray, t_plane plane)
{
	t_ray_hit_data data;

	data = ray_hit_data_init();
	if (dot_prod(ray.dir, plane.normal) != 0)
	{
		data.hit_object = PLANE;
		data.hit_point = line_plane_intersection(ray, plane);
		data.color = plane.color;
	}
	return (data);
}

bool			is_pt_between_origin_and_line(t_vector pt,
											t_vector origin, t_line line)
{
	return (dist_point_line(pt, line) <= dist_point_line(origin, line));
}

bool			is_point_in_triangle(t_vector pt, t_triangle triangle)
{
	t_line	line;
	bool	result;

	line = l(subs(triangle.point_b, triangle.point_a), triangle.point_a);
	result = is_pt_between_origin_and_line(pt, triangle.point_c, line);
	line = l(subs(triangle.point_c, triangle.point_b), triangle.point_b);
	result = result &&
				is_pt_between_origin_and_line(pt, triangle.point_a, line);
	line = l(subs(triangle.point_a, triangle.point_c), triangle.point_c);
	result = result &&
				is_pt_between_origin_and_line(pt, triangle.point_b, line);
	return (result);
}

t_ray_hit_data	ray_hit_triangle(t_line ray, t_triangle triangle)
{
	t_plane			plane_container;
	t_ray_hit_data	data;

	plane_container = pl(cross_prod(subs(triangle.point_a, triangle.point_b),
				subs(triangle.point_c, triangle.point_b)), triangle.point_b);

	data = ray_hit_plane(ray, plane_container);
	if (data.hit_object != NONE &&
	is_point_in_triangle(data.hit_point, triangle))
	{
		data.hit_object = TRIANGLE;
		data.color = triangle.color;
	}
	return (data);
}
