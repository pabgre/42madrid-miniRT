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


#include <stdio.h>
#include <unistd.h>
int main()
{
	scene my_scene;
	vector hit_point;

	ray_hit_data data;

	double fov = 10;

	vector camera_pos = vec(20, 0, 0);
	vector x_axis =  normalize(vec(0, 1, 0));
	vector y_axis =  normalize(vec(0, 0, -1));

	vector my_screen_pos = add(prod(normalize(cross_prod(x_axis, y_axis)), fov), camera_pos);

	int h = 16;
	int w = 32;


	my_scene.center = vec(0,0,0);
	my_scene.radius = 12;

	int i = -h/2;
	int j = -w/2;

	vector current_point;

	vector current_direction;

	while (i <= h/2)
	{
		j = -w/2;
		while (j <= w/2)
		{
			current_point = add(add(prod(x_axis, i), prod(y_axis, j)), my_screen_pos);
			current_direction = normalize(subs(current_point, camera_pos));
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
