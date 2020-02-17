/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:30:13 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/17 20:55:33 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void perform_raytracer(t_camera my_camera, t_scene my_scene, t_mlx *mlx)
{
	int i;
	int j;
	int pos;
	unsigned int color;
	t_vector current_point;
	t_vector current_direction;
	t_ray_hit_data data;
	pos = 0;
	color = mlx_get_color_value(mlx->ptr, 0x00ECFF);
	
	ft_init_mlx(mlx);

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
				ft_paint_pixel(pos++, color, mlx);
			else if (data.hit_object == CYLINDER)
				pos++;
			else
			{
				pos++;
			}
			j++;
		}
		i++;
	}
}
