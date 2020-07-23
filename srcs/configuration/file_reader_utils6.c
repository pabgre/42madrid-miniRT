/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader_utils6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:08:35 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/23 13:09:13 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ambient(char *buf, t_conf *conf)
{
	double	*param;

	param = get_params(buf, 4);
	conf->my_scene.ambient.radius = param[0];
	conf->my_scene.ambient.color = color(param[1], param[2], param[3]);
	free(param);
}

void		plane(char *buf, t_conf *conf)
{
	t_3d_obj	*obj;
	double		*param;

	param = get_params(buf, 9);
	obj = malloc(sizeof(t_3d_obj));
	obj->type = PLANE;
	obj->obj = plane_init(param);
	free(param);
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
}

void		scene_parser_s(char *buf, t_conf *conf)
{
	buf++;
	if (*buf == 'p')
		sphere(buf, conf);
	else if (*buf == 'q')
		square(buf, conf);
}

void		scene_parser_c(char *buf, t_conf *conf)
{
	buf++;
	if (*buf == 'y')
		cylinder(buf, conf);
	else if (*buf != 'y' && conf->flag.r)
		camera(buf, conf);
}

void		scene_parser(char *buf, t_conf *conf)
{
	if (*buf == 'R')
		resolution(buf, conf);
	else if (*buf == 'A')
		ambient(buf, conf);
	else if (*buf == 'l')
		light(buf, conf);
	else if (*buf == 's')
		scene_parser_s(buf, conf);
	else if (*buf == 'c')
		scene_parser_c(buf, conf);
	else if (*buf == 'p')
		plane(buf, conf);
	else if (*buf == 't')
		triangle(buf, conf);
	else
		conf->flag.error = 1;
}
