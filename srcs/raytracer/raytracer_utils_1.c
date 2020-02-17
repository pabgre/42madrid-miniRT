/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:58:32 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/17 16:18:13 by psan-gre         ###   ########.fr       */
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

void perform_raytracer(t_camera my_camera, t_scene my_scene)
{
	int i;
	int j;
	t_vector current_point;
	t_vector current_direction;
	t_ray_hit_data data;

	i = -(my_camera.display.h / 2);

	while (i <= my_camera.display.h/2)
	{
		j = -my_camera.display.w/2;
		while (j <= my_camera.display.w/2)
		{
			current_point = add(add(prod(my_camera.display.x_axis, i), prod(my_camera.display.y_axis, j)), my_camera.display.pos);
			current_direction = normalize(subs(current_point, my_camera.pos));
			data = trace_ray(current_point, current_direction, my_scene);
			if (data.hit_object == SPHERE)
				write(1, "SS", 2);
			else if (data.hit_object == CYLINDER)
				write(1, "CC", 2);
			else
			{
				write(1, "__", 2);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}




