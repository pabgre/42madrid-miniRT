/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytraces.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:20:01 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/17 14:22:15 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H
# include "geometry.h"
# include "camera.h"

typedef	struct	s_scene
{
	t_cylinder	my_cylinder;
	t_sphere	my_sphere;
	t_plane		my_plane;
	t_triangle	my_triangle;
}				t_scene;

typedef struct	s_ray_hit_data
{
	t_vector	hit_point;
	t_geometry	hit_object;
}				t_ray_hit_data;

t_geometry is_point_in_any_object(t_vector point, t_scene my_scene);
t_ray_hit_data trace_ray(t_vector point, t_vector direction, double step, double max_dist, t_scene my_scene);
void perform_raytracer(t_camera my_camera, t_scene my_scene);
#endif
