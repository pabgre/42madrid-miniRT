/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookTEST.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <npinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:52:19 by npinto-g          #+#    #+#             */
/*   Updated: 2020/02/26 15:52:29 by npinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		close_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr,mlx->win);
	exit (0);
}

int		pressed_key(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		close_mlx(mlx);
	}
	if (key == 37)
	{
		system("leaks a.out");
	}
	return(0);
}

int		exit_rtt(t_mlx *mlx)
{
	system("leaks a.out");		
	mlx_destroy_window(mlx->ptr,mlx->win);
	exit (0);
	return(0);
}

int		main()
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 500, 500, "test");
	mlx_hook(mlx.win, 2, 0, pressed_key, &mlx);
	mlx_hook(mlx.win, 17, 0, close_mlx, &mlx);
	mlx_loop(mlx.ptr);
}



