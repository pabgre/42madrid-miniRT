/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:04:46 by jballest          #+#    #+#             */
/*   Updated: 2020/02/17 19:27:27 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

/*static void	reverse_colors(char *img, int bpp, int size_line, int x, int y,
															unsigned int color)
{
	int i;
	int cntx;
	int cnty;

	cntx = 0;
	while (cntx < x)
	{
		cnty = 0;
		while (cnty < y)
		{
			i = ((int)cntx * (int)bpp / 8) + ((int)cnty * (int)size_line);
			img[i] = (unsigned int)color;
			img[++i] = ((unsigned int)color >> 8);
			img[++i] = ((unsigned int)color >> 16);
			img[++i] = 0;
			cnty++;
		}
		cntx++;
	}
}*/

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->window_size.x, mlx->window_size.y,
								mlx->window_title);
	mlx->img = mlx_new_image(mlx->ptr, mlx->window_size.x, mlx->window_size.y);
	mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line,
									&mlx->endian);
}
