/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:38 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/18 15:45:31 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main()
{
	t_scene my_scene;
	t_sphere my_sphere;
	t_cylinder my_cylinder;

	t_camera my_camera;
	t_screen my_screen;

	my_camera.pos = vec(20, 0, 0);
	my_camera.dist = 5;

	my_screen.h = 9;
	my_screen.w = 16;
	my_screen.x_axis = normalize(vec(0, -1, 0));
	my_screen.y_axis = normalize(vec(0, 0, 1));
	my_screen.pos = add(prod(normalize(cross_prod(my_screen.x_axis, my_screen.y_axis)), my_camera.dist), my_camera.pos);

	my_camera.display = my_screen;

	my_sphere.center = vec(0,0,0);
	my_sphere.radius = 12;

	my_cylinder.a_point = vec(0,0,20);
	my_cylinder.b_point = vec(0,0,-20);
	my_cylinder.radius = 10;

	my_scene.my_sphere = my_sphere;
	my_scene.my_cylinder = my_cylinder;

	perform_raytracer(my_camera, my_scene, 4*9, 4*16);
}
