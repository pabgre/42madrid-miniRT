/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:20:01 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/13 12:11:05 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H
# include "geometry.h"
# include "camera.h"
# include "my_mlx.h"
# include "libft.h"

typedef struct	s_light
{
	t_vector	pos;
	double		radius;
	t_color		color;
}				t_light;
typedef	struct	s_scene
{
	t_list		*light_lst;
	t_list		*obj_lst;
	t_list		*cam_lst;
	t_light		ambient;
}				t_scene;

t_ray_hit_data	ray_hit_data_init();
t_geometry is_point_in_any_object(t_vector point, t_scene my_scene);
t_ray_hit_data trace_ray(t_vector point, t_vector direction, t_scene my_scene);
void perform_raytracer(t_camera my_camera, t_scene my_scene, t_mlx *mlx);
t_ray_hit_data	hit_ray_in_any_object_lst(t_line ray, t_scene my_scene);
#endif
