/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:30:13 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/18 15:21:38 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void perform_raytracer(t_camera my_camera, t_scene my_scene, t_mlx *mlx)
{
	int i;
	int j;
	int posx;
	int posy;
	unsigned int color;
	t_vector current_point;
	t_vector current_direction;
	t_ray_hit_data data;
	posy = 0;
	color = mlx_get_color_value(mlx->ptr, 0x00ECFF);
	
	ft_init_mlx(mlx);
	printf("window_h = %f \n window_w = %f\n", mlx->window_size.y, mlx->window_size.x);
	printf("bpp = %d \n", mlx->bpp);

	i = 0;

	while (i <= my_camera.display.h)
	{
		j = 0;
		while (j <= my_camera.display.w)
		{
			posx = 0;
			current_point = add(add(prod(my_camera.display.x_axis, i -(my_camera.display.h / 2)), prod(my_camera.display.y_axis, j - my_camera.display.w/2)), my_camera.display.pos);
			current_direction = normalize(subs(current_point, my_camera.pos));
			data = trace_ray(current_point, current_direction, my_scene);
			if (data.hit_object == SPHERE)
			{
				ft_paint_pixel(i * mlx->size_line +  j * 8, color, mlx);
				write(1, "SS", 2);
			}
			/*else if (data.hit_object == CYLINDER)
				posx++;*/
			else
			{
				write(1, "__", 2);
			}
			posx++;
			j++;
		}
		write(1, "\n", 1);
		posy++;
		i++;
	}
}
