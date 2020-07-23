/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader_utils5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:55:33 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/23 13:24:36 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		cylinder(char *buf, t_conf *conf)
{
	t_3d_obj	*obj;
	double		*param;

	param = get_params(buf, 11);
	obj = malloc(sizeof(t_3d_obj));
	obj->type = CYLINDER;
	obj->obj = cylinder_init(param);
	free(param);
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
}

t_triangle	*square_tr(double *param, t_vector v, t_vector w)
{
	t_triangle *tr;

	tr = malloc(sizeof(t_triangle));
	tr->point_a = add(vec(param[0], param[1], param[2]), v);
	tr->point_b = add(vec(param[0], param[1], param[2]), w);
	tr->point_c = subs(vec(param[0], param[1], param[2]), v);
	tr->color = init_rgb(param[7], param[8], param[9]);
	return (tr);
}

t_triangle	*square_tr_b(double *param, t_vector v, t_vector w)
{
	t_triangle *tr;

	tr = malloc(sizeof(t_triangle));
	tr->point_a = subs(vec(param[0], param[1], param[2]), v);
	tr->point_b = subs(vec(param[0], param[1], param[2]), w);
	tr->point_c = add(vec(param[0], param[1], param[2]), v);
	tr->color = init_rgb(param[7], param[8], param[9]);
	return (tr);
}

void		square(char *buf, t_conf *conf)
{
	t_3d_obj	*obj;
	double		*param;
	t_vector	v;
	t_vector	w;

	param = get_params(buf, 10);
	v = normalize(vec(param[5], 0, -param[3]));
	w = normalize(cross_prod(v, vec(param[3], param[4], param[5])));
	v = prod(v, param[6] * sqrt(2) / 2);
	w = prod(w, param[6] * sqrt(2) / 2);
	obj = malloc(sizeof(t_3d_obj));
	obj->type = TRIANGLE;
	obj->obj = square_tr(param, v, w);
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
	obj = malloc(sizeof(t_3d_obj));
	obj->type = TRIANGLE;
	obj->obj = square_tr_b(param, v, w);
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
	free(param);
}

void		triangle(char *buf, t_conf *conf)
{
	t_3d_obj	*obj;
	double		*param;

	param = get_params(buf, 12);
	obj = malloc(sizeof(t_3d_obj));
	obj->type = TRIANGLE;
	obj->obj = triangle_init(param);
	free(param);
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
}
