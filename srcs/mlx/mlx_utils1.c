/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:04:46 by jballest          #+#    #+#             */
/*   Updated: 2020/03/04 13:56:06 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

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

int		pressed_key(int key, t_mlx *mlx)
{	
	printf("KEY = %d\n", key);
	if (key == 53)
	{
		close_mlx(mlx);
	}
	else if (key == 37)
	{
		system("leaks a.out");
	}
	return(0);
}
