/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:44:56 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/31 11:34:10 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	setup(t_screen my_screen, t_mlx mlx, t_conf conf)
{
	t_hook_data *hook_data;

	mlx.window_title = ft_strdup("My_test my_of my_my my_raytracer");
	mlx.window_size.x = conf.mlx.window_size.x;
	mlx.window_size.y = conf.mlx.window_size.y;
	mlx.win = mlx_new_window(mlx.ptr, my_screen.w,
			my_screen.h, mlx.window_title);
	mlx.img = mlx_new_image(mlx.ptr, my_screen.w, my_screen.h);
	mlx.img_ptr = mlx_get_data_addr(mlx.img, &mlx.bpp,
			&mlx.size_line, &mlx.endian);
	hook_data = malloc(sizeof(t_hook_data));
	hook_data->mlx = &mlx;
	hook_data->camera = conf.my_scene.cam_lst;
	hook_data->scene = &conf.my_scene;
	ft_init_mlx(&mlx);
	perform_raytracer((*(t_camera*)hook_data->camera->content),
			conf.my_scene, &mlx);
	if (conf.flag.save)
		get_bmp_image(&mlx, (size_t)mlx.bpp);
	mlx_hook(mlx.win, 2, 0, pressed_key, hook_data);
	mlx_hook(mlx.win, 17, 0, close_mlx, &mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.ptr);
}

int		main(int argc, char **argv)
{
	t_screen	my_screen;
	t_mlx		mlx;
	t_conf		conf;

	if (argc > 1)
	{
		conf = scene_conf(open(argv[1], O_RDONLY), 1);
		if (argc > 2 && strcmp("--save", argv[2]) == 0)
			conf.flag.save = 1;
	}
	else
	{
		conf = scene_conf(open("scenes/default.rt", O_RDONLY), 1);
	}
	if ((conf.flag.error || !conf.flag.r || !conf.flag.c ||
		conf.flag.no_f) && !conf.flag.save)
		return (conf_error(conf));
	my_screen = conf.my_camera.display;
	mlx.ptr = mlx_init();
	setup(my_screen, mlx, conf);
}
