/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:42:48 by pabgre            #+#    #+#             */
/*   Updated: 2020/02/17 17:03:32 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"
#include "../../includes/raytracer.h"
#include <math.h>

double	ray_hit_sphere(t_line ray, t_sphere sphere)
{
	double	disc;

	disc = pow((dot_prod(ray.dir, subs(ray.point, sphere.center))), 2);
	disc -= (dot_prod(subs(ray.point, sphere.center),
	subs(ray.point, sphere.center)) - sphere.radius * sphere.radius);
	return (disc);
}

t_ray_hit_data sphere_hit_point(t_line ray, t_sphere sphere)
{
	double disc;
	double dist_a;
	double dist_b;
	t_ray_hit_data data;

	disc = ray_hit_sphere(ray, sphere);
	data.hit_point = ray.point;
	data.hit_object = NONE;
	if (disc > 0)
	{
		dist_a = -(dot_prod(ray.dir, subs(ray.point, sphere.center)));
		dist_b = dist_a;
		dist_a += sqrt(disc);
		dist_b -= sqrt(disc);
		if (dist_a < dist_b && 0 < dist_a)
		{
			data.hit_point = add(ray.point, prod(ray.dir, dist_a));
			data.hit_object = SPHERE;
		}
		else if (0 < dist_b)
		{
			data.hit_point = add(ray.point, prod(ray.dir, dist_b));
			data.hit_object = SPHERE;
		}
	}
	return (data);
}

