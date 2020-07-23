/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:52:13 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/23 12:57:40 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		color(double r, double g, double b)
{
	t_color		color;

	color.r = limit(r, 0, 255);
	color.g = limit(g, 0, 255);
	color.b = limit(b, 0, 255);
	return (color);
}

t_sphere	*sphere_init(double *param)
{
	t_sphere	*sphere;

	sphere = (t_sphere*)malloc(sizeof(t_sphere));
	sphere->center = vec(param[0], param[1], param[2]);
	sphere->radius = param[3] / 2;
	sphere->color = color(param[4], param[5], param[6]);
	return (sphere);
}

t_cylinder	*cylinder_init(double *param)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	cylinder->center = vec(param[0], param[1], param[2]);
	cylinder->dir = normalize(vec(param[3], param[4], param[5]));
	cylinder->radius = param[6] / 2;
	cylinder->height = param[7];
	cylinder->color = color(param[8], param[9], param[10]);
	return (cylinder);
}

t_triangle	*triangle_init(double *param)
{
	t_triangle	*triangle;

	triangle = malloc(sizeof(t_triangle));
	triangle->point_a = vec(param[0], param[1], param[2]);
	triangle->point_b = vec(param[3], param[4], param[5]);
	triangle->point_c = vec(param[6], param[7], param[8]);
	triangle->color = color(param[9], param[10], param[11]);
	return (triangle);
}

t_m_plane	*plane_init(double *param)
{
	t_m_plane *plane;

	plane = malloc(sizeof(t_m_plane));
	plane->point = vec(param[0], param[1], param[2]);
	plane->normal = normalize(vec(param[3], param[4], param[5]));
	plane->color = color(param[6], param[7], param[8]);
	return (plane);
}
