/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:06:27 by jballest          #+#    #+#             */
/*   Updated: 2020/07/23 12:23:19 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "minirt.h"

int	ft_rgb_to_int(t_color rgb)
{
	int color;

	color = rgb.r;
	color = (color << 8) + rgb.g;
	color = (color << 8) + rgb.b;

	return (color);
}

t_color	init_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;

	return (color);
}

t_color	ft_rgb_shade(t_color rgb, double shade_amount)
{
	t_color color;

	shade_amount = (shade_amount >= 1 ? 1 : shade_amount);
	shade_amount = (shade_amount <= 0 ? 0 : shade_amount);
	color.r = (unsigned char)((double)rgb.r * shade_amount);
	color.g = (unsigned char)((double)rgb.g * shade_amount);
	color.b = (unsigned char)((double)rgb.b * shade_amount);
	return (color);
}

t_color	ft_rgb_tint(t_color rgb, float tint_amount)
{
	t_color color;

	color.r = rgb.r + (255 - rgb.r) * tint_amount;
	color.g = rgb.g + (255 - rgb.g) * tint_amount;
	color.b = rgb.b + (255 - rgb.b) * tint_amount;

	return (color);
}

t_color	ft_rgb_sum_ambient(t_color rgb1, t_color rgb2)
{
	t_color rescol;

	rescol.r = (rgb1.r + rgb2.r) > 255 ? 255 : (rgb1.r + rgb2.r);
	rescol.g = (rgb1.g + rgb2.g) > 255 ? 255 : (rgb1.g + rgb2.g);
	rescol.b = (rgb1.b+ rgb2.b) > 255 ? 255 : (rgb1.b + rgb2.b);
	return (rescol);
}
