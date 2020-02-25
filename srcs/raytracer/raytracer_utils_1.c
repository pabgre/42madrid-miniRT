/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:58:32 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/25 16:54:44 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_ray_hit_data	ray_hit_data_init(void)
{
	t_ray_hit_data	data;

	data.hit_point = vec(0, 0, 0);
	data.hit_object = NONE;
	data.color.r = 255;
	data.color.g = 255;
	data.color.b = 255;
	data.normal = vec(0,0,0);
	return (data);
}

t_ray_hit_data		hit_ray_in_any_object(t_line ray, t_scene my_scene)
{
	t_ray_hit_data	hit_data;
	t_ray_hit_data	hit_data_aux;

	hit_data = sphere_hit_point(ray, my_scene.my_sphere);
	hit_data_aux = cylinder_hit_point(ray, my_scene.my_cylinder);
	if (hit_data.hit_object != NONE)
	{
		if (hit_data_aux.hit_object != NONE && which_is_near(
			hit_data_aux.hit_point, hit_data.hit_point, ray.point))
			hit_data = hit_data_aux;
	}
	else
		hit_data = hit_data_aux;
	hit_data_aux = ray_hit_triangle(ray, my_scene.my_triangle);
	if (hit_data.hit_object != NONE)
	{
		if (hit_data_aux.hit_object != NONE && which_is_near(
			hit_data_aux.hit_point, hit_data.hit_point, ray.point))
			hit_data = hit_data_aux;
	}
	else
		hit_data = hit_data_aux;
	return (hit_data);
}

t_ray_hit_data	trace_ray(t_vector point, t_vector direction, t_scene my_scene)
{
	t_ray_hit_data	hit_data;
	t_line			ray;
	double			fac;

	ray.point = point;
	ray.dir = direction;
	fac = 1;

	hit_data = hit_ray_in_any_object(ray, my_scene);
	if (hit_data.hit_object != NONE)
	{
		ray.point = hit_data.hit_point;
		ray.dir = normalize(subs(my_scene.my_light.pos, hit_data.hit_point));
		if (hit_ray_in_any_object(ray, my_scene).hit_object)
			fac = 1;
		else
			fac = 1 - dot_prod(hit_data.normal, ray.dir);
		hit_data.color = ft_rgb_shade(hit_data.color, fac);
	}

	return (hit_data);
}
