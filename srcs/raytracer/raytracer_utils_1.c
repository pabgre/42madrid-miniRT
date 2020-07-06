/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:58:32 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/06 12:23:02 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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

t_ray_hit_data	ray_hit_this_obj(t_line ray, t_3d_obj *obj_data)
{
	if (obj_data->type == SPHERE)
	{
		return (sphere_hit_point(ray, *(t_sphere*)(obj_data->obj)));
	}
	else if (obj_data->type == CYLINDER)
	{
		return (cylinder_hit_point(ray, *(t_cylinder*)(obj_data->obj)));
	}
	else if (obj_data->type == TRIANGLE)
	{
		return (ray_hit_triangle(ray, *(t_triangle*)(obj_data->obj)));
	}
	else
		return (ray_hit_data_init());
}

t_ray_hit_data	hit_ray_in_any_object_lst(t_line ray, t_scene my_scene)
{
	t_list			*aux;
	t_ray_hit_data	data;
	t_ray_hit_data	data_aux;

	data = ray_hit_data_init();
	aux = my_scene.obj_lst;
	while (aux != NULL)
	{
		data_aux = ray_hit_this_obj(ray, (t_3d_obj*)aux->content);
		if (data_aux.hit_object != NONE)
		{
			if (data.hit_object == NONE)
				data = data_aux;
			else
			{
				if (data_aux.hit_object != NONE && which_is_near(
					data_aux.hit_point, data.hit_point, ray.point))
					data = data_aux;
			}
		}
		aux = aux->next;
	}
	return (data);
}

/*t_ray_hit_data		hit_ray_in_any_object(t_line ray, t_scene my_scene)
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
}*/

t_ray_hit_data	trace_ray(t_vector point, t_vector direction, t_scene my_scene)
{
	t_ray_hit_data	hit_data;
	t_line			ray;
	double			fac;
	double			ratio;
	double			ambient;

	ray.point = point;
	ray.dir = direction;
	ambient = 0.8;

	hit_data = hit_ray_in_any_object_lst(ray, my_scene);
	if (hit_data.hit_object != NONE)
	{
		ray.dir = normalize(subs(my_scene.my_light.pos, hit_data.hit_point));
		ray.point = add(hit_data.hit_point, prod(ray.dir, 0.000001));
		ratio = my_scene.my_light.radius;
		fac = 1;
		if (!hit_ray_in_any_object_lst(ray, my_scene).hit_object)
			fac = (1 - (dot_prod(normalize(hit_data.normal), \
									normalize(ray.dir)) * ratio));
		fac = fac > 1 ? 1 : fac;
		hit_data.color = ft_rgb_shade(hit_data.color, fac * ambient);
	}

	return (hit_data);
}
