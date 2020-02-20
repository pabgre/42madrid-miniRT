/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:38 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/20 21:30:26 by psan-gre         ###   ########.fr       */
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

	my_camera.pos = vec(20, 0, 0);
	my_camera.dist = 5;

	my_screen.h = 9;
	my_screen.w = 16;
	my_screen.x_axis = normalize(vec(0, -1, 0));
	my_screen.y_axis = normalize(vec(0, 0, 1));
	my_screen.pos = add(prod(normalize(cross_prod(my_screen.x_axis, my_screen.y_axis)), my_camera.dist), my_camera.pos);

	my_camera.display = my_screen;

	my_sphere.center = vec(0,10,0);
	my_sphere.radius = 0;

	double angle = 1;

	my_cylinder.center = vec(0, 0, 2);
	my_cylinder.dir = normalize(vec(1 * sin(angle) ,1 * cos(angle), 0 * sin(angle)));
	my_cylinder.radius = 2;
	my_cylinder.height = 10;

	my_scene.my_sphere = my_sphere;
	my_scene.my_cylinder = my_cylinder;

	mlx.ptr = mlx_init();
	mlx.window_title = ft_strdup("Test");
	mlx.window_size.x = 640;
	mlx.window_size.y = 360;
	mlx.win = mlx_new_window(mlx.ptr, my_screen.w, my_screen.h, mlx.window_title);
	mlx.img = mlx_new_image(mlx.ptr, my_screen.w, my_screen.h);
	mlx.img_ptr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, &mlx.endian);

	//perform_raytracer(my_camera, my_scene, &mlx);
	perform_raytracer(my_camera, my_scene, &mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.ptr);
}
