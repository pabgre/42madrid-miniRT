/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <npinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:42:48 by pabgre            #+#    #+#             */
/*   Updated: 2020/03/05 12:52:44 by npinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"
#include "../../includes/raytracer.h"
#include "../../includes/polinom.h"
#include <math.h>

t_polinom2		sphere_ray_equation(t_line ray, t_sphere sphere)
{
	t_polinom2	pol;

	pol.a = dot_prod(ray.dir, ray.dir);
	pol.b = 2 * dot_prod(ray.dir, subs(ray.point, sphere.center));
	pol.c = dot_prod(subs(ray.point, sphere.center),
	subs(ray.point, sphere.center)) - sphere.radius * sphere.radius;
	return (pol);
}

double			ray_hit_sphere(t_line ray, t_sphere sphere)
{
	double		disc;
	t_polinom2	sphere_pol;

	sphere_pol = sphere_ray_equation(ray, sphere);
	disc = discr(sphere_pol) / 4;
	return (disc);
}
#include <stdio.h>

t_ray_hit_data	sphere_hit_point(t_line ray, t_sphere sphere)
{
	double			disc;
	double			dist_a;
	double			dist_b;
	t_ray_hit_data	data;

	disc = ray_hit_sphere(ray, sphere);
	data = ray_hit_data_init();
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
		data.normal = normalize(subs(data.hit_point, sphere.center));
		data.color = sphere.color;
	}
	/*printf(" CENTER X = %f \n", sphere.center.x);
	printf(" CENTER Z = %f \n", sphere.center.z);
	printf(" RADIUS = %f \n", sphere.radius);*/
	return (data);
}

