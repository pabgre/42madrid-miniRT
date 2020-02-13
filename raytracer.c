/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:58:32 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/12 17:46:54 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector/vector.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "camera.h"

typedef enum e_geometry{
	NONE, SPHERE
}				geometry;

typedef	struct s_scene
{
	vector center;
	double radius;
}				scene;

typedef struct s_ray_hit_data
{
	vector hit_point;
	geometry hit_object;
}				ray_hit_data;

bool is_point_in_sphere(vector point, double radius, vector center)
{
	bool equation;
	vector point_relativ;

	point_relativ = subs(point, center);
	equation = (dot_prod(point_relativ, point_relativ) <= radius * radius);
	return(equation);
}


ray_hit_data trace_ray(vector point, vector direction, double step, double max_dist, scene my_scene)
{
	double dist;
	ray_hit_data hit_data;

	dist = 0;
	while(dist < max_dist && !is_point_in_sphere(point, my_scene.radius, my_scene.center))
	{
		point = add(point, prod(direction, step));
		dist += step;
	}
	if (dist < max_dist)
		hit_data.hit_object = SPHERE;
	else
		hit_data.hit_object = NONE;
	hit_data.hit_point = point;
	return (hit_data);
}

void perform_raytracer(camera my_camera, scene my_scene)
{
	int i;
	int j;
	vector current_point;
	vector current_direction;
	ray_hit_data data;

	i = -(my_camera.display.h / 2);

	while (i <= my_camera.display.h/2)
	{
		j = -my_camera.display.w/2;
		while (j <= my_camera.display.w/2)
		{
			current_point = add(add(prod(my_camera.display.x_axis, i), prod(my_camera.display.y_axis, j)), my_camera.display.pos);
			current_direction = normalize(subs(current_point, my_camera.pos));
			data = trace_ray(current_point, current_direction, 0.1, 50, my_scene);
			if (data.hit_object == SPHERE)
				write(1, "SS", 2);
			else
			{
				write(1, "__", 2);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int main()
{
	scene my_scene;

	camera my_camera;
	screen my_screen;

	my_camera.pos = vec(20, 0, 0);
	my_camera.fov = 10;

	my_screen.h = 16;
	my_screen.w = 32;
	my_screen.x_axis = normalize(vec(0, 1, 0));
	my_screen.y_axis = normalize(vec(0, 0, -1));
	my_screen.pos = add(prod(normalize(cross_prod(my_screen.x_axis, my_screen.y_axis)), my_camera.fov), my_camera.pos);

	my_camera.display = my_screen;

	my_scene.center = vec(0,0,0);
	my_scene.radius = 12;

	perform_raytracer(my_camera, my_scene);
}
