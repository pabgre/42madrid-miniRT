/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <npinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:04:46 by jballest          #+#    #+#             */
/*   Updated: 2020/07/21 09:09:09 by npinto-g         ###   ########.fr       */
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

void	pan_cam(int key, t_hook_data *hook_data)
{
	if (key == 123)
		{
			((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->pos, prod(((t_camera*)hook_data->camera->content)->display.y_axis,-10));
			((t_camera*)hook_data->camera->content)->display.pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(((t_camera*)hook_data->camera->content)->display.y_axis,-10));
		}

	else if (key == 124)
		{
			((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->pos, prod(((t_camera*)hook_data->camera->content)->display.y_axis,10));
			((t_camera*)hook_data->camera->content)->display.pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(((t_camera*)hook_data->camera->content)->display.y_axis,10));

		}
	else if (key == 125)
		{
			((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->pos, prod(((t_camera*)hook_data->camera->content)->display.x_axis,10));
			((t_camera*)hook_data->camera->content)->display.pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(((t_camera*)hook_data->camera->content)->display.x_axis,10));
		}
	else if (key == 126)
		{
			((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->pos, prod(((t_camera*)hook_data->camera->content)->display.x_axis,-10));
			((t_camera*)hook_data->camera->content)->display.pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(((t_camera*)hook_data->camera->content)->display.x_axis,-10));
		}
}

void	zoom(int key, t_hook_data *hook_data)
{
	t_vector normal;
	double theta;

	normal = normalize(cross_prod(((t_camera*)hook_data->camera->content)->display.y_axis,
									((t_camera*)hook_data->camera->content)->display.x_axis));
	theta = 3.14 / 36;
	if (key == 13)
	{
		normal = rotate(normal, ((t_camera*)hook_data->camera->content)->display.y_axis, theta);
		((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(normal, -((t_camera*)hook_data->camera->content)->dist));
		((t_camera*)hook_data->camera->content)->display.x_axis = normalize(cross_prod(normal, ((t_camera*)hook_data->camera->content)->display.y_axis));
	}
	else if (key == 1)
	{
		normal = rotate(normal, ((t_camera*)hook_data->camera->content)->display.y_axis, -theta);
		((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(normal, -((t_camera*)hook_data->camera->content)->dist));
		((t_camera*)hook_data->camera->content)->display.x_axis = normalize(cross_prod(normal, ((t_camera*)hook_data->camera->content)->display.y_axis));
	}
	//rotation??
	else if (key == 0)
	{
		normal = rotate(normal, ((t_camera*)hook_data->camera->content)->display.x_axis, -theta);
		((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(normal, -((t_camera*)hook_data->camera->content)->dist));
		((t_camera*)hook_data->camera->content)->display.y_axis = normalize(cross_prod(((t_camera*)hook_data->camera->content)->display.x_axis, normal));
	}
	else if (key == 2)
	{
		normal = rotate(normal, ((t_camera*)hook_data->camera->content)->display.x_axis, theta);
		((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(normal, -((t_camera*)hook_data->camera->content)->dist));
		((t_camera*)hook_data->camera->content)->display.y_axis = normalize(cross_prod(((t_camera*)hook_data->camera->content)->display.x_axis,normal));
	}
	else if (key == 6)
	{
		((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->pos, prod(normal,10));
		((t_camera*)hook_data->camera->content)->display.pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(normal,10));
	}
	else if (key == 7)
	{
		((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->pos, prod(normal,-10));
		((t_camera*)hook_data->camera->content)->display.pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(normal,-10));
	}
	//world rot??
	else if (key == 12)
	{
		normal = rotate(normal, ((t_camera*)hook_data->camera->content)->display.x_axis, theta);
		((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(normal, -((t_camera*)hook_data->camera->content)->dist));
		((t_camera*)hook_data->camera->content)->display.y_axis = normalize(cross_prod(((t_camera*)hook_data->camera->content)->display.x_axis,normal));				
		((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->pos, prod(((t_camera*)hook_data->camera->content)->display.y_axis,-6));
		((t_camera*)hook_data->camera->content)->display.pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(((t_camera*)hook_data->camera->content)->display.y_axis,-6));
	}
	else if (key == 14)
	{
		normal = rotate(normal, ((t_camera*)hook_data->camera->content)->display.x_axis, -theta);
		((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(normal, -((t_camera*)hook_data->camera->content)->dist));
		((t_camera*)hook_data->camera->content)->display.y_axis = normalize(cross_prod(((t_camera*)hook_data->camera->content)->display.x_axis, normal));
		((t_camera*)hook_data->camera->content)->pos = add(((t_camera*)hook_data->camera->content)->pos, prod(((t_camera*)hook_data->camera->content)->display.y_axis,6));
		((t_camera*)hook_data->camera->content)->display.pos = add(((t_camera*)hook_data->camera->content)->display.pos, prod(((t_camera*)hook_data->camera->content)->display.y_axis,6));
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
	else if (key == 13 || (key >= 0 && key <= 2) || key == 6 || key == 7 || key == 12 || key == 14)
	{
		zoom(key, hook_data);
		perform_raytracer((*(t_camera*)hook_data->camera->content), *hook_data->scene, hook_data->mlx);
		mlx_put_image_to_window(hook_data->mlx->ptr, hook_data->mlx->win, hook_data->mlx->img, 0, 0);
		printf("Zoomzoom?\n");
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
