/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:30:13 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/01 11:21:31 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void perform_raytracer(t_camera my_camera, t_scene my_scene, t_mlx *mlx)
{
	int x;
	int y;
	double x_plane;
	double y_plane;
	t_vector current_point;
	t_vector current_direction;
	t_ray_hit_data data;

	ft_init_mlx(mlx);
	printf("window_h = %f \n window_w = %f\n", mlx->window_size.y, mlx->window_size.x);
	printf("bpp = %d \n", mlx->bpp);

	x = 0;
	data = ray_hit_data_init();

	while (x < mlx->window_size.y)
	{
		y = 0;
		while (y < mlx->window_size.x)
		{
			x_plane = (x + 1.0)/ mlx->window_size.y * my_camera.display.h - my_camera.display.h / 2.0;
			y_plane = (y + 1.0)/ mlx->window_size.x * my_camera.display.w - my_camera.display.w / 2.0;
			current_point = add(add(prod(my_camera.display.x_axis, x_plane) , prod(my_camera.display.y_axis, y_plane)), my_camera.display.pos);
			current_direction = normalize(subs(current_point, my_camera.pos));
			data = trace_ray(current_point, current_direction, my_scene);
			if (data.hit_object != NONE)
				ft_paint_pixel(x * mlx->size_line +  y * mlx->bpp / 8, ft_rgb_to_int(data.color), mlx);
			else
				ft_paint_pixel(x * mlx->size_line +  y * mlx->bpp / 8, mlx_get_color_value(mlx->ptr, 0xFFFFFF), mlx);
			y += 1;
		}
		x += 1;
	}
}
