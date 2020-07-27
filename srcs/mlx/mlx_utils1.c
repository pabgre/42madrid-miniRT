/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:04:46 by jballest          #+#    #+#             */
/*   Updated: 2020/07/27 13:27:11 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "hook_data.h"

void	ft_paint_pixel(int i, unsigned int color, t_mlx *mlx)
{
	mlx->img_ptr[i] = (unsigned int)color;
	mlx->img_ptr[++i] = ((unsigned int)color >> 8);
	mlx->img_ptr[++i] = ((unsigned int)color >> 16);
	mlx->img_ptr[++i] = 0;
}

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->ptr, mlx->window_size.x, mlx->window_size.y,
								mlx->window_title);
	mlx->img = mlx_new_image(mlx->ptr, mlx->window_size.x, mlx->window_size.y);
	mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line,
									&mlx->endian);
}

int		close_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}

void	pan_cam_y(t_hook_data *hook_data, int dir)
{
	((t_camera*)hook_data->camera->content)->pos =
	add(((t_camera*)hook_data->camera->content)->pos,
	prod(((t_camera*)hook_data->camera->content)->display.y_axis,
	dir * 10));
	((t_camera*)hook_data->camera->content)->display.pos =
	add(((t_camera*)hook_data->camera->content)->display.pos,
	prod(((t_camera*)hook_data->camera->content)->display.y_axis,
	dir * 10));
}

void	pan_cam_x(t_hook_data *hook_data, int dir)
{
	((t_camera*)hook_data->camera->content)->pos =
	add(((t_camera*)hook_data->camera->content)->pos,
	prod(((t_camera*)hook_data->camera->content)->display.x_axis,
			dir * 10));
	((t_camera*)hook_data->camera->content)->display.pos =
	add(((t_camera*)hook_data->camera->content)->display.pos,
	prod(((t_camera*)hook_data->camera->content)->display.x_axis,
			dir * 10));
}
