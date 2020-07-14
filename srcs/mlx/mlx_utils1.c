/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <npinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:04:46 by jballest          #+#    #+#             */
/*   Updated: 2020/07/14 08:47:32 by npinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
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
	//mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->window_size.x, mlx->window_size.y,
								mlx->window_title);
	mlx->img = mlx_new_image(mlx->ptr, mlx->window_size.x, mlx->window_size.y);
	mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line,
									&mlx->endian);
}

int		close_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr,mlx->win);
	exit (0);
}

void	pan_cam( int key, t_hook_data *hook_data)
{
	if (key == 123)
		{
			((t_camera*)hook_data->camera->content)->pos.z -= 5;
			((t_camera*)hook_data->camera->content)->display.pos.z -= 5;
		}

	else if (key == 124)
		{
			((t_camera*)hook_data->camera->content)->pos.z += 5;
			((t_camera*)hook_data->camera->content)->display.pos.z += 5;
	
		}
	else if (key == 125)
		{
			((t_camera*)hook_data->camera->content)->pos.y += 5;
			((t_camera*)hook_data->camera->content)->display.pos.y += 5;
		}
	else if (key == 126)
		{
			((t_camera*)hook_data->camera->content)->pos.y -= 5;
			((t_camera*)hook_data->camera->content)->display.pos.y -= 5;
		}
}

int		pressed_key(int key, t_hook_data *hook_data)
{
	printf("KEY = %d\n", key);
	if (key == 53)
	{
		close_mlx(hook_data->mlx);
	}
	else if (key == 37)
	{
		system("leaks coolMiniRT");
	}
	else if (key == 18)
	{
		(*(t_camera*)hook_data->camera->content).pos = vec((*(t_camera*)hook_data->camera->content).pos.x + 1, (*(t_camera*)hook_data->camera->content).pos.y, (*(t_camera*)hook_data->camera->content).pos.z);
		perform_raytracer((*(t_camera*)hook_data->camera->content), *hook_data->scene, hook_data->mlx);
	}
	else if (key >= 123 && key <= 126)
	{
		pan_cam(key, hook_data);
		perform_raytracer(*(t_camera*)hook_data->camera->content, *hook_data->scene, hook_data->mlx);
		mlx_put_image_to_window(hook_data->mlx->ptr, hook_data->mlx->win, hook_data->mlx->img, 0, 0);
		printf("image updated?\n");
	}
	else if (key == 19)
	{
		hook_data->camera = hook_data->camera->next;
		if (hook_data->camera == NULL){
			hook_data->camera = hook_data->scene->cam_lst;
		}
		perform_raytracer((*(t_camera*)hook_data->camera->content), *hook_data->scene, hook_data->mlx);
		mlx_put_image_to_window(hook_data->mlx->ptr, hook_data->mlx->win, hook_data->mlx->img, 0, 0);
		printf("camera ZZZZ updated?\n");
	}
	return(0);
}
