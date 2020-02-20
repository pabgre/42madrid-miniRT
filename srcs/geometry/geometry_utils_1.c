/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:00:41 by pabgre            #+#    #+#             */
/*   Updated: 2020/02/20 20:26:11 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"
#include "../../includes/vector.h"

#define ABS(a) ((a) < 0 ? -(a) : (a))

t_vector	closest_point_line(t_vector point, t_line my_line)
{
    t_vector closest_point;

    closest_point = add(my_line.point, prod(my_line.dir, dot_prod(subs(point,my_line.point), my_line.dir)));
    return (closest_point);
}


double		dist_point_line(t_vector point, t_line my_line)
{
    t_vector closest_point;

    closest_point = closest_point_line(point, my_line);
    return (distance(point, closest_point));
}

double		dist_point_plane(t_vector point, t_plane my_plane)
{
    double dist;

    dist = ABS(dot_prod(point, my_plane.normal) - dot_prod(my_plane.normal, my_plane.point));
    dist = dist / magnitude(my_plane.normal);

    return (dist);
}

t_vector	line_plane_intersection(t_line line, t_plane plane)
{
	double dist;

	dist = 0;
	if(dot_prod(line.dir, plane.normal) != 0)
	{
		dist = (dot_prod(plane.normal, plane.point) - dot_prod(line.point, plane.normal)) / dot_prod(line.dir, plane.normal);
	}
	return (add(line.point, prod(line.dir, dist)));
}

t_vector	closest_point(t_vector point_a, t_vector point_b, t_vector origin)
{
	if (distance(point_a, origin) <= distance(point_b, origin))
		return (point_a);
	else
		return (point_b);
}

t_plane		pl(t_vector normal, t_vector point)
{
	t_plane plane;

	plane.normal = normalize(normal);
	plane.point = point;

	return (plane);
}

t_line		l(t_vector dir, t_vector origin)
{
	t_line line;

	line.dir = normalize(dir);
	line.point = origin;
	return (line);
}
