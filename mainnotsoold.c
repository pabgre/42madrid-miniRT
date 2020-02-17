/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainnotsoold.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:53:54 by jballest          #+#    #+#             */
/*   Updated: 2020/02/17 15:06:40 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void reverse_colors(char *img, int bpp, int size_line, int x, int y, unsigned int color)
{
	int i;
	int cntx = 0;
	while(cntx < x)
	{
		int cnty = 0;
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
}

int main()
{
	t_mlx	mlx;
	//char *img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
	int x = 100;
	int y = 100;

	//int cnt = 0;

	unsigned int color;
	//unsigned int color2;

	//int curx;
	//int cury;

	//curx = 0;
	//cury = 0;

	x = 1024;
	y = 768;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, x, y, "Test window");
	mlx.img = mlx_new_image(mlx.ptr, 100, 100);
	mlx.img_ptr = mlx_get_data_addr(mlx.img, &bpp, &size_line, &endian);
	color = mlx_get_color_value(mlx.ptr, 0x00ECFF);
	printf("endian = %d\n", endian);
	reverse_colors(mlx.img_ptr, bpp, size_line, 100, 100, color);
	/*while (cnt < (10000))
	{
		int x;

		x = 4 * cnt;
		color2 = color;

		while (x < 4 * cnt + 4)
		{
			mlx.img_ptr[x] = color2;
			color2 = color2 >> 8;
			x++;
		}
		cnt++;
	}*/
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, x/2, y/2);
	mlx_loop(mlx.ptr);
}
