/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:30:13 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/27 12:33:31 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	aux_perform_raytracer(t_ray_hit_data data, t_vector2_int screen,
							t_mlx *mlx, t_scene scene)
{
	if (data.hit_object != NONE)
		ft_paint_pixel(screen.x * mlx->size_line + screen.y * mlx->bpp / 8,
						ft_rgb_to_int(data.color), mlx);
	else
		ft_paint_pixel(screen.x * mlx->size_line + screen.y * mlx->bpp / 8,
			mlx_get_color_value(mlx->ptr, ft_rgb_to_int(
				ft_rgb_shade(scene.ambient.color, scene.ambient.radius))), mlx);
}

void	perform_raytracer(t_camera cam, t_scene scene, t_mlx *mlx)
{
	t_vector2_int		screen;
	t_vector2_double	plane;
	t_vector			c_pt;
	t_vector			current_direction;
	t_ray_hit_data		data;

	screen.x = 0;
	data = ray_hit_data_init();
	while (++screen.x < mlx->window_size.y)
	{
		screen.y = 0;
		while (++screen.y < mlx->window_size.x)
		{
			plane.x = (screen.x + 0.0) /
				mlx->window_size.y * cam.display.h - cam.display.h / 2.0;
			plane.y = (screen.y + 0.0) /
				mlx->window_size.x * cam.display.w - cam.display.w / 2.0;
			c_pt = add(add(prod(cam.display.x_axis, plane.x),
						prod(cam.display.y_axis, plane.y)), cam.display.pos);
			current_direction = normalize(subs(c_pt, cam.pos));
			data = trace_ray(c_pt, current_direction, scene);
			aux_perform_raytracer(data, screen, mlx, scene);
		}
	}
}
