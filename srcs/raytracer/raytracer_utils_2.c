/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:30:13 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/20 19:13:46 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void perform_raytracer(t_camera my_camera, t_scene my_scene, t_mlx *mlx)
{
	int x;
	int y;
	double x_plane;
	double y_plane;
	int color;
	int color2;
	int color3;
	t_color rgb;
	rgb.r = 54;
	rgb.g = 227;
	rgb.b = 80;
	t_vector current_point;
	t_vector current_direction;
	t_ray_hit_data data;
	color = mlx_get_color_value(mlx->ptr, 0x00ECFF);
	color2 = mlx_get_color_value(mlx->ptr, 0xED5132);
	color3 = mlx_get_color_value(mlx->ptr, 0xFFFFFF);

	ft_init_mlx(mlx);
	printf("window_h = %f \n window_w = %f\n", mlx->window_size.y, mlx->window_size.x);
	printf("bpp = %d \n", mlx->bpp);

	x = 0;

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
			if (data.hit_object == SPHERE)
			{
				ft_paint_pixel(x * mlx->size_line +  y * mlx->bpp / 8, ft_rgb_tint(rgb, 0.1), mlx);
				//write(1, "SS", 2);
			}
			else if (data.hit_object == CYLINDER)
			{
				ft_paint_pixel(x * mlx->size_line +  y * mlx->bpp / 8, color, mlx);
				//write(1, "CC", 2);
			}
			else if (data.hit_object == PLANE)
			{
				ft_paint_pixel(x * mlx->size_line +  y * mlx->bpp / 8, color3, mlx);
			}
			else
			{
				ft_paint_pixel(x * mlx->size_line +  y * mlx->bpp / 8, color2, mlx);
				//write(1, "__", 2);
			}
			y += 1;
		}
		//write(1, "\n", 1);
		x += 1;
	}
}
