/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:38 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/18 15:26:09 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main()
{
	t_scene my_scene;
	t_sphere my_sphere;
	t_cylinder my_cylinder;

	t_camera my_camera;
	t_screen my_screen;

	t_mlx mlx;

	my_camera.pos = vec(10, 0, 0);
	my_camera.fov = 5;

	my_screen.h = 320/20;
	my_screen.w = 640/20;
	my_screen.x_axis = normalize(vec(0, -1, 0));
	my_screen.y_axis = normalize(vec(0, 0, 1));
	my_screen.pos = add(prod(normalize(cross_prod(my_screen.x_axis, my_screen.y_axis)), my_camera.fov), my_camera.pos);

	my_camera.display = my_screen;

	my_sphere.center = vec(0,0,0);
	my_sphere.radius = 5;

	my_cylinder.a_point = vec(0,0,20);
	my_cylinder.b_point = vec(0,0,-20);
	my_cylinder.radius = 10;

	my_scene.my_sphere = my_sphere;
	my_scene.my_cylinder = my_cylinder;

	mlx.ptr = mlx_init();
	mlx.window_title = ft_strdup("Test");
	mlx.window_size.x = my_screen.w;
	mlx.window_size.y = my_screen.h;
	mlx.win = mlx_new_window(mlx.ptr, my_screen.w, my_screen.h, mlx.window_title);
	mlx.img = mlx_new_image(mlx.ptr, my_screen.w, my_screen.h);
	mlx.img_ptr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, &mlx.endian);
	
	perform_raytracer(my_camera, my_scene, &mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.ptr);
}
