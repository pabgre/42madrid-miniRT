/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:21:48 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/23 12:27:41 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "minirt.h"

void	ft_rgb_normalize(t_color *rgb)
{
	int max;

	max = 255;
	if (rgb->r > max)
		max = rgb->r;
	if (rgb->g > max)
		max = rgb->g;
	if (rgb->b > max)
		max = rgb->b;
	rgb->r *= 255 / max;
	rgb->g *= 255 / max;
	rgb->b *= 255 / max;
}

t_color	ft_color_multiply(t_color rgb1, t_color rgb2)
{
	t_color rescol;

	rescol.r = rgb1.r * rgb2.r / 255;
	rescol.g = rgb1.g * rgb2.g / 255;
	rescol.b = rgb1.b * rgb2.b / 255;
	return (rescol);
}

t_color	ft_color_addition(t_color rgb1, t_color rgb2)
{
	t_color rescol;

	rescol.r = rgb1.r + rgb2.r;
	rescol.r = (rescol.r > 255) ? 255 : rescol.r;
	rescol.g = rgb1.g + rgb2.g;
	rescol.g = (rescol.g > 255) ? 255 : rescol.g;
	rescol.b = rgb1.b + rgb2.b;
	rescol.b = (rescol.b > 255) ? 255 : rescol.b;

	return (rescol);
}

t_color	ft_color_screen(t_color rgb1, t_color rgb2)
{
	t_color	rescol;

	rescol.r = 255 - (((255 - rgb1.r) * (255 - rgb2.r)) / 255);
	rescol.g = 255 - (((255 - rgb1.g) * (255 - rgb2.g)) / 255);
	rescol.b = 255 - (((255 - rgb1.b) * (255 - rgb2.b)) / 255);
	return (rescol);
}

t_color ft_color_layer_opacity(t_color rgb, double alpha)
{
	alpha = 100 / alpha;

	rgb.r = rgb.r / alpha;
	rgb.g = rgb.g / alpha;
	rgb.b = rgb.b / alpha;

	return (rgb);
}
