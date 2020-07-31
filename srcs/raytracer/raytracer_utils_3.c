/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:41:16 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/31 11:28:56 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		w_to_file(size_t fd, int num, ...)
{
	va_list		args;
	int			value;

	va_start(args, num);
	value = va_arg(args, uint32_t);
	while (num--)
	{
		write(fd, &value, sizeof(uint32_t));
		value = va_arg(args, uint32_t);
	}
	va_end(args);
	return (value);
}

int		intpow(int base, int exponent)
{
	int		power;

	power = base;
	exponent = (exponent > 24) ? 24 : exponent;
	while (exponent-- > 1)
	{
		power = power * base;
	}
	return (power);
}

void	w_header(size_t fd, size_t width, size_t height, size_t bpp)
{
	t_header	header;

	header.signature = ft_strdup("BM");
	header.filesize = width * height * bpp / 8 + 54;
	header.reserved = 0;
	header.dataoffset = 54;
	write(fd, header.signature, 2);
	w_to_file(fd, 3, header.filesize, header.reserved, header.dataoffset);
	free(header.signature);
}

void	w_infoheader(size_t fd, uint32_t width, uint32_t height, uint16_t bpp)
{
	t_info_header	info;

	info.size_info_header = 40;
	info.planes = 1;
	info.compression = 0;
	info.comp_size = 0;
	info.xppm = 0;
	info.yppm = 0;
	info.palette = (uint32_t)intpow(2, bpp);
	info.imp_color = 0;
	w_to_file(fd, 3, info.size_info_header, width, height);
	write(fd, &info.planes, 2);
	write(fd, &bpp, 2);
	w_to_file(fd, 4, info.compression, info.comp_size, info.xppm, info.yppm);
	w_to_file(fd, 2, info.palette, info.imp_color);
}

void	get_bmp_image(t_mlx *mlx, size_t bpp)
{
	size_t			fd;
	char			*pixel;
	t_vector2_int	win_size;
	t_vector2_int	img_size;

	pixel = mlx_get_data_addr(mlx->img, &mlx->bpp,
	&mlx->size_line, &mlx->endian);
	win_size = vec2_int(mlx->window_size.x, mlx->window_size.y);
	img_size.y = 0;
	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0640);
	w_header(fd, win_size.x, win_size.y, bpp);
	w_infoheader(fd, win_size.x, win_size.y, bpp);
	pixel += (win_size.x * win_size.y * bpp / 8) - win_size.x * bpp / 8;
	while (img_size.y < (int)win_size.y)
	{
		img_size.x = 0;
		while (img_size.x++ < (int)win_size.x)
		{
			write(fd, pixel, 4);
			pixel += 4;
		}
		pixel -= win_size.x * (size_t)mlx->bpp / 8 * 2;
		img_size.y++;
	}
	close(fd);
}
