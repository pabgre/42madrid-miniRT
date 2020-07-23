/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader_utils4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:54:16 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/23 13:04:00 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_mcd(int a, int b)
{
	int c;

	c = 1;
	while (b != 0)
	{
		c = b;
		b = a % b;
		a = c;
	}
	return (c);
}

void	camera(char *buf, t_conf *conf)
{
	t_screen	my_screen;
	t_camera	*my_camera;
	double		*param;
	int			mcd;
	double		angle;

	conf->flag.c = 1;
	my_camera = malloc(sizeof(t_camera));
	param = get_params(buf, 7);
	mcd = ft_mcd(conf->mlx.window_size.x, conf->mlx.window_size.y);
	my_screen.w = conf->mlx.window_size.x / mcd;
	my_screen.h = conf->mlx.window_size.y / mcd;
	angle = limit(param[6], 0, 180);
	angle *= 3.14 / 360.0;
	my_camera->dist = (my_screen.w / 2.0) / tan(angle);
	my_screen.x_axis = normalize(cross_prod(
						vec(param[3], param[4], param[5]), vec(0, 0, -1)));
	my_screen.y_axis = normalize(vec(0, 0, -1));
	my_screen.pos = vec(param[0], param[1], param[2]);
	my_camera->pos = add(prod(normalize(vec(param[3], param[4], param[5])),
				-my_camera->dist), my_screen.pos);
	free(param);
	my_camera->display = my_screen;
	ft_lstadd_front(&(conf->my_scene.cam_lst), ft_lstnew(my_camera));
}

void	resolution(char *buf, t_conf *conf)
{
	double		*param;

	param = get_params(buf, 2);
	conf->mlx.window_size.x = limit(param[0], 1, 2560);
	conf->mlx.window_size.y = limit(param[1], 1, 1440);
	conf->flag.r = 1;
	free(param);
}

void	light(char *buf, t_conf *conf)
{
	t_light		*current_light;
	double		*param;

	current_light = malloc(sizeof(t_light));
	param = get_params(buf, 7);
	current_light->pos = vec(param[0], param[1], param[2]);
	current_light->radius = limit(param[3], 0, 1);
	current_light->color = color(param[4], param[5], param[6]);
	free(param);
	ft_lstadd_front(&(conf->my_scene.light_lst), ft_lstnew(current_light));
}

void	sphere(char *buf, t_conf *conf)
{
	t_3d_obj	*obj;
	double		*param;

	param = get_params(buf, 7);
	obj = malloc(sizeof(t_3d_obj));
	obj->type = SPHERE;
	obj->obj = sphere_init(param);
	free(param);
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
}
