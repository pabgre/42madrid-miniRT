/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:58:32 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/27 12:06:49 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray_hit_data	ray_hit_data_init(void)
{
	t_ray_hit_data	data;

	data.hit_point = vec(0, 0, 0);
	data.hit_object = NONE;
	data.color.r = 255;
	data.color.g = 255;
	data.color.b = 255;
	data.normal = vec(0, 0, 0);
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
	else if (obj_data->type == PLANE)
	{
		return (ray_hit_math_plane(ray, *(t_m_plane*)(obj_data->obj)));
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

t_ray_hit_data	light_info(t_scene scene, t_ray_hit_data hit_data)
{
	float	fac;
	t_list	*aux;
	t_line	ray;
	t_light	c_light;
	t_color lightcolor;

	aux = scene.light_lst;
	lightcolor = init_rgb(0, 0, 0);
	while (aux != NULL)
	{
		c_light = *((t_light*)aux->content);
		ray.dir = normalize(subs(c_light.pos, hit_data.hit_point));
		ray.point = add(hit_data.hit_point, prod(ray.dir, 0.000001));
		fac = 0;
		if (!hit_ray_in_any_object_lst(ray, scene).hit_object || !which_is_near(
			ray.point, c_light.pos, hit_ray_in_any_object_lst(ray, scene).hit_point))
			fac = dot_prod(normalize(hit_data.normal), normalize(ray.dir));
		fac = fac < 0 ? 0 : fac;
		lightcolor = ft_rgb_sum(lightcolor,
						ft_rgb_shade(c_light.color, fac * c_light.radius));
		aux = aux->next;
	}
	lightcolor = ft_rgb_sum(lightcolor, ft_rgb_shade(scene.ambient.color, scene.ambient.radius));
	hit_data.color = ft_color_multiply(hit_data.color, lightcolor);
	lightcolor = ft_color_layer_opacity(lightcolor, 60);
	hit_data.color = ft_color_screen(hit_data.color, lightcolor);
	return (hit_data);
}

t_ray_hit_data	trace_ray(t_vector point, t_vector direction, t_scene my_scene)
{
	t_ray_hit_data	hit_data;
	t_line			ray;

	ray.point = point;
	ray.dir = direction;

	hit_data = hit_ray_in_any_object_lst(ray, my_scene);
	if (hit_data.hit_object != NONE)
	{
		hit_data = light_info(my_scene, hit_data);
	}

	return (hit_data);
}
