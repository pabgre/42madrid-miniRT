/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:35:46 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/21 13:50:21 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"
#include "../../includes/vector.h"


t_vector	closest_point_line(t_vector point, t_line my_line)
{
	t_vector closest_point;

	closest_point = add(my_line.point,
	prod(my_line.dir, dot_prod(subs(point, my_line.point), my_line.dir)));
	return (closest_point);
}

double		dist_point_line(t_vector point, t_line my_line)
{
	t_vector	closest_point;

	closest_point = closest_point_line(point, my_line);
	return (distance(point, closest_point));
}


t_vector	line_plane_intersection(t_line line, t_m_plane pl)
{
	double dist;

	dist = 0;
	if (dot_prod(line.dir, pl.normal) != 0)
	{
		dist =
		(dot_prod(pl.normal, pl.point) - dot_prod(line.point, pl.normal))
		/ dot_prod(line.dir, pl.normal);
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

bool	which_is_near(t_vector pt_a, t_vector pt_b, t_vector origin)
{
	return (distance(pt_a, origin) <= distance(pt_b, origin));
}

