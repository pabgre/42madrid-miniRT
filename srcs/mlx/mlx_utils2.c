/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:26:42 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/27 13:27:41 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "hook_data.h"

void	pan_cam(int key, t_hook_data *hook_data)
{
	if (key == 123)
	{
		pan_cam_y(hook_data, -1);
	}
	else if (key == 124)
	{
		pan_cam_y(hook_data, 1);
	}
	else if (key == 125)
	{
		pan_cam_x(hook_data, 1);
	}
	else if (key == 126)
	{
		pan_cam_x(hook_data, -1);
	}
}

void	local_rotation_x(t_hook_data *hook_data, double theta, t_vector normal)
{
	normal = rotate(normal,
		((t_camera*)hook_data->camera->content)->display.x_axis, theta);
	((t_camera*)hook_data->camera->content)->pos =
		add(((t_camera*)hook_data->camera->content)->display.pos,
		prod(normal, -((t_camera*)hook_data->camera->content)->dist));
	((t_camera*)hook_data->camera->content)->display.y_axis =
		normalize(cross_prod(
			((t_camera*)hook_data->camera->content)->display.x_axis, normal));
}

void	local_rotation_y(t_hook_data *hook_data, double theta, t_vector normal)
{
	normal = rotate(normal,
		((t_camera*)hook_data->camera->content)->display.y_axis, theta);
	((t_camera*)hook_data->camera->content)->pos =
		add(((t_camera*)hook_data->camera->content)->display.pos,
		prod(normal, -((t_camera*)hook_data->camera->content)->dist));
	((t_camera*)hook_data->camera->content)->display.x_axis =
		normalize(cross_prod(normal,
		((t_camera*)hook_data->camera->content)->display.y_axis));
}

void	global_rotation(t_hook_data *hook_data, double theta,
						t_vector normal, int dir)
{
	normal = rotate(normal,
		((t_camera*)hook_data->camera->content)->display.x_axis, theta);
	((t_camera*)hook_data->camera->content)->pos =
		add(((t_camera*)hook_data->camera->content)->display.pos,
			prod(normal, -((t_camera*)hook_data->camera->content)->dist));
	((t_camera*)hook_data->camera->content)->display.y_axis =
		normalize(cross_prod(
				((t_camera*)hook_data->camera->content)->display.x_axis,
					normal));
	((t_camera*)hook_data->camera->content)->pos =
		add(((t_camera*)hook_data->camera->content)->pos,
			prod(((t_camera*)hook_data->camera->content)->display.y_axis,
				dir * 6));
	((t_camera*)hook_data->camera->content)->display.pos =
		add(((t_camera*)hook_data->camera->content)->display.pos,
			prod(((t_camera*)hook_data->camera->content)->display.y_axis,
				dir * 6));
}

void	perform_zoom(t_hook_data *hook_data, t_vector normal, int dir)
{
	((t_camera*)hook_data->camera->content)->pos =
		add(((t_camera*)hook_data->camera->content)->pos,
			prod(normal, dir * 10));
	((t_camera*)hook_data->camera->content)->display.pos =
		add(((t_camera*)hook_data->camera->content)->display.pos,
			prod(normal, dir * 10));
}
