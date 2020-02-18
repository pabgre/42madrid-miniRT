/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:20:01 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/18 17:47:18 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H
# include "geometry.h"
# include "camera.h"
# include "my_mlx.h"

typedef	struct	s_scene
{
	t_cylinder	my_cylinder;
	t_sphere	my_sphere;
	t_plane		my_plane;
	t_triangle	my_triangle;
}				t_scene;

t_ray_hit_data	ray_hit_data_init(t_vector point);
t_geometry is_point_in_any_object(t_vector point, t_scene my_scene);
t_ray_hit_data trace_ray(t_vector point, t_vector direction, t_scene my_scene);
void perform_raytracer(t_camera my_camera, t_scene my_scene, t_mlx *mlx);
#endif
