/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:43:46 by psan-gre          #+#    #+#             */
/*   Updated: 2020/03/02 18:03:37 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_ray_hit_data	ray_hit_this_obj(t_line ray, t_3d_obj *obj_data)
{

	if (obj_data->type == SPHERE)
		return (sphere_hit_point(ray, *(t_sphere*)(obj_data->obj)));
	else if (obj_data->type == CYLINDER)
		return (cylinder_hit_point(ray, *(t_cylinder*)(obj_data->obj)));
	else if (obj_data->type == TRIANGLE)
		return (ray_hit_triangle(ray, *(t_triangle*)(obj_data->obj)));
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


