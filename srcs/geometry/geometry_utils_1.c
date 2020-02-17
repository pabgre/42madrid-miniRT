/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:00:41 by pabgre            #+#    #+#             */
/*   Updated: 2020/02/17 13:54:23 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

#define ABS(a) ((a) < 0 ? -(a) : (a))

t_vector closest_point_line(t_vector point, t_line my_line)
{
    t_vector closest_point;

    closest_point = add(my_line.point, prod(my_line.dir, dot_prod(subs(point,my_line.point), my_line.dir)));
    return (closest_point);
}


double dist_point_line(t_vector point, t_line my_line)
{
    t_vector closest_point;

    closest_point = closest_point_line(point, my_line);
    return (distance(point, closest_point));
}

double dist_point_plane(t_vector point, t_plane my_plane)
{
    double dist;

    dist = ABS(dot_prod(point, my_plane.normal) - dot_prod(my_plane.normal, my_plane.point));
    dist = dist / magnitude(my_plane.normal);

    return (dist);
}
