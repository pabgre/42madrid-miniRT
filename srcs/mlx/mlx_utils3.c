/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:27:57 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/27 13:28:26 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "hook_data.h"

void	zoom(int key, t_hook_data *hook_data)
{
	t_vector	normal;
	double		theta;

	normal = normalize(
		cross_prod(((t_camera*)hook_data->camera->content)->display.y_axis,
					((t_camera*)hook_data->camera->content)->display.x_axis));
	theta = 3.14 / 36;
	if (key == 13)
		local_rotation_y(hook_data, theta, normal);
	else if (key == 1)
		local_rotation_y(hook_data, -theta, normal);
	else if (key == 0)
		local_rotation_x(hook_data, -theta, normal);
	else if (key == 2)
		local_rotation_x(hook_data, theta, normal);
	else if (key == 6)
		perform_zoom(hook_data, normal, 1);
	else if (key == 7)
		perform_zoom(hook_data, normal, -1);
	else if (key == 12)
		global_rotation(hook_data, theta, normal, -1);
	else if (key == 14)
		global_rotation(hook_data, -theta, normal, 1);
}

void	reset_raytracer(t_hook_data *hook_data)
{
	perform_raytracer(*(t_camera*)hook_data->camera->content,
	*hook_data->scene, hook_data->mlx);
	mlx_put_image_to_window(hook_data->mlx->ptr,
	hook_data->mlx->win, hook_data->mlx->img, 0, 0);
}

int		pressed_key(int key, t_hook_data *hook_data)
{
	if (key == 53)
		close_mlx(hook_data->mlx);
	else if (key == 37)
		system("leaks coolMiniRT");
	else if (key == 13 || (key >= 0 && key <= 2) ||
			key == 6 || key == 7 || key == 12 || key == 14)
	{
		zoom(key, hook_data);
		reset_raytracer(hook_data);
	}
	else if (key >= 123 && key <= 126)
	{
		pan_cam(key, hook_data);
		reset_raytracer(hook_data);
	}
	else if (key == 19)
	{
		hook_data->camera = hook_data->camera->next;
		if (hook_data->camera == NULL)
			hook_data->camera = hook_data->scene->cam_lst;
		reset_raytracer(hook_data);
	}
	return (0);
}
