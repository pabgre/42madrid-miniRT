/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:38 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/08 12:49:18 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef	struct	s_header
{
	char		*signature;
	uint32_t	filesize;
	uint32_t	reserved;
	uint32_t	dataoffset;
}				t_header;

typedef	struct s_info_header
{
	size_t		size_info_header;
	uint16_t	planes;
	uint32_t	compression;
	uint32_t	comp_size;
	uint32_t	xppm;
	uint32_t	yppm;
	uint32_t	palette;
	uint32_t	imp_color;
}				t_info_header;


int		w_to_file(size_t fd, int num, ...)
{
	va_list		args;
	int			value;

	va_start(args, num);
	value = va_arg(args, uint32_t);
	while(num--)
	{
		//printf("%d\n", value);
		write(fd, &value, sizeof(uint32_t));
		value = va_arg(args, uint32_t);
	}
	va_end(args);
	return (value);
}

int		intpow(int base, int exponent)
{
	int		power;

	power = base;
	exponent = (exponent > 24) ? 24 : exponent;
	while (exponent-- > 1)
	{
		power = power * base;
	}
	return (power);
}

void	w_header(size_t fd, size_t width, size_t height, size_t bpp)
{
	t_header	header;

	header.signature = ft_strdup("BM");//ft_strdup
	header.filesize = width * height * bpp / 8 + 54;
	header.reserved = 0;
	header.dataoffset = 54;
	write(fd, header.signature, 2);
	w_to_file(fd, 3, header.filesize, header.reserved, header.dataoffset);
	free(header.signature);
}

void	w_infoheader(size_t fd, uint32_t width, uint32_t height, uint16_t bpp)
{
	t_info_header	info;

	info.size_info_header = 40;
	info.planes = 1;
	info.compression = 0;
	info.comp_size = 0;
	info.xppm = 0;
	info.yppm = 0;
	info.palette = (uint32_t)intpow(2, bpp);
	info.imp_color = 0;
	w_to_file(fd, 3, info.size_info_header, width, height);
	write(fd, &info.planes, 2);
	write(fd, &bpp, 2);
	w_to_file(fd, 4, info.compression, info.comp_size, info.xppm, info.yppm);
	w_to_file(fd, 2, info.palette, info.imp_color);
}

void	get_bmp_image(t_mlx	*mlx)
{
	size_t		fd;
	size_t		width = (size_t)mlx->window_size.x;
	size_t		height = (size_t)mlx->window_size.y;
	size_t		bpp = (size_t)mlx->bpp;
	char		*pixel = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);

	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0640);
	w_header(fd, width, height, bpp);
	w_infoheader(fd, width, height, bpp);
	int		h = 0;
	int		w;
	pixel += (width * height * bpp / 8) - width * bpp / 8;
	while (h < (int)height)
	{
		w = 0;
		while (w < (int)width)
		{
			write(fd, pixel, 4);
			pixel += 4;
			w++;
		}
		pixel -= width * bpp / 8 * 2;
		h++;
	}
	//write (fd, pixel, width * height * bpp / 8);
	close(fd);
}

int main(int argc,char **argv)
{
	t_screen my_screen;
	t_mlx mlx;
	t_conf	conf;


	if (argc > 1)
	{
		conf = scene_conf(argv[1]);
		if ( argc > 2 && strcmp("--save", argv[2]) == 0)
			conf.flag.save = 1;
	}
	else
	{
		conf = scene_conf("default.rt");
	}
	if (conf.flag.error || !conf.flag.r)
		return (-1);
	my_screen = conf.my_camera.display;
	mlx.ptr = mlx_init();
	//printf("ptr:%p", mlx.ptr);
	//printf("\n\t Leak chasing : conf 0 : %p\n", &conf);
	mlx.window_title = ft_strdup("My_test my_of my_my my_raytracer");
	mlx.window_size.x = conf.mlx.window_size.x;
	mlx.window_size.y = conf.mlx.window_size.y;

	mlx.win = mlx_new_window(mlx.ptr, my_screen.w, my_screen.h, mlx.window_title);
	mlx.img = mlx_new_image(mlx.ptr, my_screen.w, my_screen.h);
	mlx.img_ptr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, &mlx.endian);


	//t_3d_obj *obj_data;
	//t_sphere *my_sphere;
	//t_cylinder *my_cylinder;


	/*my_sphere = malloc(sizeof(t_sphere));
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
	ft_lstadd_front(&conf.my_scene.obj_lst, ft_lstnew(obj_data));*/

	/*my_cylinder = malloc(sizeof(t_cylinder));
	my_cylinder->center = vec(0,0,0);
	my_cylinder->color = init_rgb(0,0,255);
	my_cylinder->dir = vec(0,1,0);
	my_cylinder->height = 15;
	my_cylinder->radius = 2;

	obj_data = malloc(sizeof(t_3d_obj));
	obj_data->type = CYLINDER;
	obj_data->obj = my_cylinder;
	ft_lstadd_front(&conf.my_scene.obj_lst, ft_lstnew(obj_data));*/
	//perform_raytracer(my_camera, my_scene, &mlx);
	perform_raytracer(conf.my_camera, conf.my_scene, &mlx);
	if (conf.flag.save)
		get_bmp_image(&mlx);
	mlx_hook(mlx.win, 2, 0, pressed_key, &mlx);
	mlx_hook(mlx.win, 17, 0, close_mlx, &mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.ptr);
}
