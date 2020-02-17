/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:58:32 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/17 14:24:45 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"


t_geometry is_point_in_any_object(t_vector point, t_scene my_scene)
{
	t_geometry result;

	if (is_point_in_sphere(point, my_scene.my_sphere))
		result = SPHERE;
	else if (is_point_in_cylinder(point, my_scene.my_cylinder))
		result = CYLINDER;
	else
		result = NONE;
	return (result);
}

t_ray_hit_data trace_ray(t_vector point, t_vector direction, double step, double max_dist, t_scene my_scene)
{
	double dist;
	t_ray_hit_data hit_data;

	dist = 0;
	hit_data.hit_object = NONE;
	while (dist < max_dist && hit_data.hit_object == NONE)
	{
		hit_data.hit_object = is_point_in_any_object(point, my_scene);
		point = add(point, prod(direction, step));
		dist += step;
	}
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
			data = trace_ray(current_point, current_direction, 0.1, 50, my_scene);
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




