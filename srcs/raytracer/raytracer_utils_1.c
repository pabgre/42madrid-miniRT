/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:58:32 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/17 16:36:47 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_geometry hit_ray_in_any_object(t_line ray, t_scene my_scene)
{
	t_geometry result;

	if (ray_hit_sphere(ray, my_scene.my_sphere))
		result = SPHERE;
	else
		result = NONE;
	return (result);
}

t_ray_hit_data trace_ray(t_vector point, t_vector direction, t_scene my_scene)
{
	t_ray_hit_data hit_data;
	t_line ray;

	ray.point = point;
	ray.dir = direction;

	hit_data.hit_object = hit_ray_in_any_object(ray, my_scene);
	hit_data.hit_point = point;
	return (hit_data);
}






