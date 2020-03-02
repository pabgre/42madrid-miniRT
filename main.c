/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:38 by psan-gre          #+#    #+#             */
/*   Updated: 2020/03/02 13:57:05 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc,char **argv)
{
	t_screen my_screen;
	t_mlx mlx;
	t_conf	conf;
	t_light my_light;

	if (argc > 1)
	{ 
		conf = scene_conf(argv[1]);
	}
	else
	{
		conf = scene_conf("default.rt");
	}
	my_light.pos = vec(20,0,-10);
	my_screen = conf.my_camera.display;
	conf.my_scene.my_light = my_light;
	conf_printer(conf);
	mlx.ptr = mlx_init();
	printf("ptr:%p", mlx.ptr);
	mlx.window_title = ft_strdup("Test");
	mlx.window_size.x = conf.mlx.window_size.x;
	mlx.window_size.y = conf.mlx.window_size.y;
	
	mlx.win = mlx_new_window(mlx.ptr, my_screen.w, my_screen.h, mlx.window_title);
	mlx.img = mlx_new_image(mlx.ptr, my_screen.w, my_screen.h);
	mlx.img_ptr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, &mlx.endian);
	

	//perform_raytracer(my_camera, my_scene, &mlx);
	perform_raytracer(conf.my_camera, conf.my_scene, &mlx);
	
	mlx_hook(mlx.win, 2, 0, pressed_key, &mlx);
	mlx_hook(mlx.win, 17, 0, close_mlx, &mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.ptr);
}
