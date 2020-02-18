/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:58:32 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/18 16:21:24 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_ray_hit_data	ray_hit_data_init(t_vector point)
{
	t_ray_hit_data data;

	data.hit_point = point;
	data.hit_object = NONE;
	data.color.r = 255;
	data.color.g = 255;
	data.color.b = 255;
	return (data);
}

t_geometry		hit_ray_in_any_object(t_line ray, t_scene my_scene)
{
	t_geometry		result;
	t_ray_hit_data	hit_data;

	hit_data = sphere_hit_point(ray, my_scene.my_sphere);
	if (hit_data.hit_object == SPHERE)
		result = SPHERE;
	else
		result = NONE;
	return (result);
}

t_ray_hit_data	trace_ray(t_vector point, t_vector direction, t_scene my_scene)
{
	t_ray_hit_data	hit_data;
	t_line			ray;

	ray.point = point;
	ray.dir = direction;

	hit_data.hit_object = hit_ray_in_any_object(ray, my_scene);
	hit_data.hit_point = point;
	return (hit_data);
}
