/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:38 by psan-gre          #+#    #+#             */
/*   Updated: 2020/03/02 20:18:10 by psan-gre         ###   ########.fr       */
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


	t_3d_obj *obj_data;
	t_sphere *my_sphere;
	t_cylinder *my_cylinder;


	my_sphere = malloc(sizeof(t_sphere));
	my_sphere->center = vec(0,0,0);
	my_sphere->radius = 10;
	my_sphere->color = init_rgb(255, 255, 0);

	obj_data = malloc(sizeof(t_3d_obj));
	obj_data->type = SPHERE;
	obj_data->obj = my_sphere;
	conf.my_scene.obj_lst = ft_lstnew(obj_data);

	my_sphere = malloc(sizeof(t_sphere));
	my_sphere->center = vec(0,0,10);
	my_sphere->radius = 10;
	my_sphere->color = init_rgb(255, 0, 0);

	obj_data = malloc(sizeof(t_3d_obj));
	obj_data->type = SPHERE;
	obj_data->obj = my_sphere;
	ft_lstadd_front(&conf.my_scene.obj_lst, ft_lstnew(obj_data));

	my_cylinder = malloc(sizeof(t_cylinder));
	my_cylinder->center = vec(0,0,0);
	my_cylinder->color = init_rgb(0,0,255);
	my_cylinder->dir = vec(0,1,0);
	my_cylinder->height = 15;
	my_cylinder->radius = 2;

	obj_data = malloc(sizeof(t_3d_obj));
	obj_data->type = CYLINDER;
	obj_data->obj = my_cylinder;
	ft_lstadd_front(&conf.my_scene.obj_lst, ft_lstnew(obj_data));
	//perform_raytracer(my_camera, my_scene, &mlx);
	perform_raytracer(conf.my_camera, conf.my_scene, &mlx);

	mlx_hook(mlx.win, 2, 0, pressed_key, &mlx);
	mlx_hook(mlx.win, 17, 0, close_mlx, &mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.ptr);
}
