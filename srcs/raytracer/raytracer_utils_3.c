/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:41:16 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/31 10:58:40 by psan-gre         ###   ########.fr       */
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

void	get_bmp_image(t_mlx	*mlx)
{
	size_t		fd;
	size_t		width = (size_t)mlx->window_size.x;
	size_t		height = (size_t)mlx->window_size.y;
	size_t		bpp = (size_t)mlx->bpp;
	char		*pixel = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);
	int		h = 0;
	int		w;

	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0640);
	w_header(fd, width, height, bpp);
	w_infoheader(fd, width, height, bpp);
	pixel += (width * height * bpp / 8) - width * bpp / 8;
	while (h < (int)height)
	{
		w = 0;
		while (w < (int)width)
		{
			write(fd, pixel, 4);
			pixel += 4;
			w++;
		}
		pixel -= width * bpp / 8 * 2;
		h++;
	}
	close(fd);
}
